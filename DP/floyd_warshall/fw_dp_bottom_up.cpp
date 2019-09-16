/*  
    The below solution is a combination of bottom up approach and recursive calls
    it is easily convertible to the corresponding iterative solution
*/

#include <bits/stdc++.h>
#define MAX_VAL 9999

using namespace std;

vector<vector<int>> fw_dp_bu(int k,int n,const vector<vector<int>>& prev_mat){
 
     vector<vector<int>>  mat_k (n+1,vector<int>(n+1,0));

    if( k  > n){           
        return prev_mat;
    }

    for(int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++){
            mat_k[i][j] = std::min( prev_mat[i][j] , prev_mat[i][k]+prev_mat[k][j] );
        }
    }

    return fw_dp_bu(k+1,n,mat_k);
}
int main() {
    int n;

    cout << "Enter the number of vertices : ";
    cin >> n;

    cout << " Enter the weight matrix  for the graph (write -1 for INF weight ): " << endl;

    vector<vector<int>>  mat_0 (n+1,vector<int>(n+1,0));
    int tmp;

    
    for(int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++){
            cin >> tmp;
            if( tmp == -1){
                    mat_0[i][j] = MAX_VAL;
            } else {
                mat_0[i][j] = tmp;
            }
        }
    }

    vector<vector<int>>  sol_mat = fw_dp_bu(1,n,mat_0);
    cout << " The solution is : \n" ;
     for(int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++){
            cout << sol_mat[i][j] << " ";
        }
        cout << endl;
    }

}