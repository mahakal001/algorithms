#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> v ;
	for(int i = 1 ; i <= 1000 ; i++ ) 
	{
		v.push_back(i) ;
	}
	std::random_shuffle(v.begin(),v.end());

	for(const auto& ch :  v)
		cout << ch << " " ;
	cout << "Enter number to search for \n" ;
	int num ;
	cin >> num ;

	int low = 0 ;
	int high = v.size()-1;
	int mid;
	int steps=0
		;	
	while(low <= high ){
		mid = (low+high)/2;
		steps++;
		if(v[mid] == num){
			cout <<  mid << endl;
			break;
		}
		
		if(v[mid] < num ){
			low = mid+1;
		} 
		else {
			high = mid-1;
		}

	}
	cout << endl << steps << endl;
return 0;
}


