#include <bits/stdc++.h>

long long lcs_top_down(std::string& seq1,std::string& seq2,long long n,long long m,
                        std::vector<std::vector<long long>>& dyn_table){

                if( n == 0 || m == 0){
                    return 0;
                }

                if ( dyn_table[n-1][m-1] == -1){
                    if(seq1[n-1] == seq2[m-1]){
                        dyn_table[n-1][m-1] = 1 + lcs_top_down(seq1,seq2,n-1,m-1,dyn_table);
                    } else {
                        dyn_table[n-1][m-1] = std::max(lcs_top_down(seq1,seq2,n-1,m,dyn_table),lcs_top_down(seq1,seq2,n,m-1,dyn_table));
                    }
                }
                
                return dyn_table[n-1][m-1];
}

int main(){

    std::string seq1;
    std::string seq2;
   


    std::cout << "Enter the first string : ";
    std::cin >> seq1;
    std::cout << "Enter the second string : ";
    std::cin >> seq2;
    long long n = seq1.length();
    long long m = seq2.length() ;
     std::vector<std::vector<long long>> dyn_table(n+1,std::vector<long long>(m+1,-1));

    std::cout << " The longest common subsequence size is : " << lcs_top_down(seq1,seq2,n,m, dyn_table) << std::endl;

    return 0;
}