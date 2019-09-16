#include <bits/stdc++.h>

static long long function_calls;    // to record the number of function calls
clock_t start_time,end_time;        // to estimate the time taken by the function
std::vector < long long > myTable;  // special table to store the computed values

long long fib(long long n){
    function_calls++;

    if( n == 0 || n == 1){  // Basic case
        return n;
    }

     if ( myTable[n] != -1 ) {  // when the value is already computed , we simply return
         return myTable[n];
     }

     myTable[n] =  fib(n-1) + fib(n-2);     // myTable[n] store fibonacci of n

     return myTable[n];
}

int main() {

    long long n;


    std::cout << " Enter the number ( non-negative  ) :  " ;
    std::cin >> n ;
    
    for(int i = 0 ; i  < n+1 ; i++){    // initialization of the table
        myTable.push_back(-1);
    }
    
    myTable[0] = 0 , myTable[1] = 1;
    

    start_time =  clock();
    std::cout <<  "fib(" << n << ")" << " is  : " << fib(n) << std::endl;
    end_time   =  clock();

    std::cout << " Total function calls : " << function_calls << std::endl;
    std::cout << " Total Time taken : " << double(end_time - start_time ) / double(CLOCKS_PER_SEC)  << std::setprecision(5) << " secs " << std::endl ;
    

    return 0;

}