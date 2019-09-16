/* Fractional knapsack problem
 Algorithm Steps :

 1. Compute profit to weight ratio for all items.
 2. sort the digits in non-decreasing order of this ratio
 3. select items from the begining of this list with as much
    portion as possible that can be added.
 4. calculate the net worth of the knapsack according to the 
    added items.
*/
 
 #include <bits/stdc++.h>
using namespace std;
struct item {
        float weight;
        float profit;
        float pwr;
    };
bool sortrev( struct item& a,struct item& b){
    return a.pwr > b.pwr ;
}

void fractional_knapsack(vector<float> weight,vector<float> profit,float knapSack_capacity){
    
    int n = weight.size();
    
    vector<item> items  ; // profit to weight ratio
    for(int i = 0 ; i < n ; i++){
        items.push_back({weight[i],profit[i],float(profit[i]/weight[i])});
    }

    sort(items.begin(),items.end(),sortrev);

    float rem_capacity = knapSack_capacity;
    float t_profit = 0 ;
    int i;
    for(i = 0 ; i < n ; i++){
        if(  rem_capacity > 0 && items[i].weight < rem_capacity){
            rem_capacity -= items[i].weight;
            t_profit += items[i].profit;
        }
        else {
            break;
        }
    }
    if( rem_capacity > 0 && i < n ){
        t_profit += (items[i].pwr * rem_capacity) ; 
    }

    cout << t_profit << endl;
}

int main(int argc,char** argv){
    vector<float> wt;
    vector<float> pr;
    int n,c;
    cin >> n;
    cin >> c;
    int tmp;
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        wt.push_back(tmp);
        cin >> tmp ; 
        pr.push_back(tmp);
    }
    fractional_knapsack(wt,pr,c);
    return 0;
}