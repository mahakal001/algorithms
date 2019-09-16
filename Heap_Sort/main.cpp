#include "heap.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc,char** argv)
{
	std::vector<int> intArr;
	size_t sizeOfVector{};
	cout << "How many integer you wanna add \n"  << endl;
	cin >> sizeOfVector ;
	for(int i=0,tmp=0 ; i < sizeOfVector ; i++){
		cin >> tmp;
		intArr.push_back(tmp);
	}
	/* =====================  Heap Class Usage ============ */
	std::vector<int> sortedArr = heap_sort(intArr);

    for(auto elem : sortedArr){
            cout << elem << " " ;
    }
    cout << endl;

	return 0;
}
