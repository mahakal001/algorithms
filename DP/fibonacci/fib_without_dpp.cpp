#include <bits/stdc++.h>

static long long function_calls;
clock_t start_time,end_time;

long long fib(long long n){

    function_calls++ ;
    if( n == 0 || n == 1){
        return n;
    }

    return fib(n-1) + fib(n-2);
}
int main(){

    long long n;

    std::cout << " Enter the number ( non-negative  ) :  "   ; 
    std::cin >> n;

    start_time = clock();
    std::cout <<  "fib(" << n << ")" << " is  : " << fib(n) << std::endl;  
    end_time = clock();


    std::cout << " Total function calls : " << function_calls << std::endl;
    std::cout << " Total Time taken : " << double(end_time - start_time ) / double(CLOCKS_PER_SEC) << std::setprecision(5) << " secs " << std::endl ;
    

    return 0;

}
