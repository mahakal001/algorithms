#include <bits/stdc++.h>

std::vector<long long> w_arr ;
std::vector<long long> p_arr ;


long long knapSack_0_1 (long long index,long long capacity , 
                        std::vector<std::vector<long long>>& dyn_table ){

    if( index == 0 || capacity == 0){
        return 0;
    }

    if( dyn_table[index][capacity] != -1){
        return dyn_table[index][capacity] ;
    }


    dyn_table[index][capacity] = std::max( (w_arr[index] > capacity ? 0 : (p_arr[index] + knapSack_0_1(index-1,capacity-w_arr[index],dyn_table))),
                                           knapSack_0_1(index-1,capacity,dyn_table));
    
    return dyn_table[index][capacity];
}


int main(void){

    long long n;
    std::cout << " Enter number of items : ";
    std::cin >> n;

    long long capacity;
    std::cout <<  " Enter the maximum capapcity of knapsack : " ;
    std::cin >> capacity ;

    std::vector<std::vector<long long>> dyn_table(n+1, std::vector<long long> (capacity+1, -1));

    std::cout << "Enter weight and profits of " << n << " items \n";
    long long tmp;

    for(long long int i = 0 ; i < n ; i++){
        std::cout <<  i << " ) \t\t\t Enter weight :  " ;
        std::cin >> tmp;
        w_arr.push_back(tmp);

        std::cout << " \t\t\t Enter profit : " ;
        std::cin >> tmp;
        p_arr.push_back(tmp);
    }

    std::cout << " maximum benefit that can be achived is : " << knapSack_0_1(n,capacity,dyn_table) << "\n";

    return 0        ;

}
