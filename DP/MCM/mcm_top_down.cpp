#include <bits/stdc++.h>

static long long function_calls ;

long long mcm_top_down(std::vector<long long>& mats_dims,std::vector<std::vector<int>>& dyn_table,
                        long long n,long long start_i,long long end_j){


    function_calls++;
    
    if( start_i == end_j){        // we don't need to multiply a matrix with itself,so return 0
        return 0;
    }


    long long minimum_val = INT64_MAX;

    for(long long k = start_i ; k <  end_j ; k++ ){ 
        if(dyn_table[start_i][k] == -1){
            dyn_table[start_i][k] = mcm_top_down(mats_dims,dyn_table,n,start_i,k);
        }

        if( dyn_table[k+1][end_j] == -1){
            dyn_table[k+1][end_j] = mcm_top_down(mats_dims,dyn_table,n,k+1,end_j);
        }

        long long total_product_ops =  dyn_table[start_i][k] + 
                                       dyn_table[k+1][end_j] +
                                       mats_dims[start_i-1]*mats_dims[k]*mats_dims[end_j];

        if ( total_product_ops < minimum_val ){
            minimum_val = total_product_ops;
        }
    }
    return minimum_val;
}

long long mcm(std::vector<long long>& mats_dims ){
    long long n = mats_dims.size() - 1;
    std::vector<std::vector<long long>> dyn_table(n+1, std::vector<long long> (n+1, -1));
    for( int i = 1 ; i <= n ; i++){
        dyn_table[i][i] = 0 ;
    }

    dyn_table[1][n] = mcm_top_down(mats_dims,dyn_table,n,1,n);
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
