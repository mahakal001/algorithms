#include <bits/stdc++.h>

static long long function_calls ;

long long mcm_bottom_up(std::vector<long long>& mats_dims,std::vector<std::vector<long long>>& dyn_table,
                        long long n , long long start_i,long long end_j){

for(long long len = 2 ; len <= n ; len++ ){
    for( long long i = 1 ; i <= (n - len + 1) ; i++){

        long long j = i + len - 1; 

        dyn_table[i][j] = INT64_MAX;

        for(long long k = i ; k <= j-1 ; k++){
            long long tmp = dyn_table[i][k] + dyn_table[k+1][j] + mats_dims[i-1]*mats_dims[k]*mats_dims[j];

            if( tmp < dyn_table[i][j]){
                dyn_table[i][j] = tmp;
            }
        }
    }
}
    return dyn_table[start_i][end_j];
}

long long mcm(std::vector<long long>& mats_dims ){
    long long n = mats_dims.size() - 1;
    std::vector<std::vector<long long>> dyn_table(n+1, std::vector<long long> (n+1, -1));
    for( int i = 1 ; i <= n ; i++){
        dyn_table[i][i] = 0 ;
    }

    dyn_table[1][n] = mcm_bottom_up(mats_dims,dyn_table,n,1,n);
    return  dyn_table[1][n];
}

int main(void){

    std::cout << " Enter the total number of matrices :  " ;
    long long n;
    std::cin >> n;


    std::cout <<  "Enter the matrices dimesnion in the required format : " ;
    std::vector<long long> mats_dims;
    long long tmp;
    for(long long i = 0 ; i <= n ; i++){
        std::cin >> tmp;
        mats_dims.push_back(tmp);
    }

    clock_t start_time = clock();
    std::cout << " The result is : " << mcm(mats_dims) << std::endl;
    clock_t end_time = clock();


    std::cout << " Total function calls : " << function_calls << std::endl;
    std::cout << " Total Time taken : " << double(end_time - start_time ) / double(CLOCKS_PER_SEC)  << std::setprecision(5) << " secs " << std::endl ;
    
    return 0;
}