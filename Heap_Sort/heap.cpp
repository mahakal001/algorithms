#include "heap.h"

static int heapSize;

int parent(int index) { return floor( index/2.0 ) ; }
int left  (int index) { return 2*index ; }
int right (int index) { return 2*index + 1 ; }

/* 
LOOP invariant: At the start of each iteration of the while loop each node 
                index + 1;index + 2,....., n is the root of a max-heap.
Time Complexity : Loose Upper Bound = O(nLogn)
                  Tight Upper Bound = O(n)
*/

void build_max_heap(std::vector<int>& intVector){
   auto index = floor(intVector.size()/2.0) ;
   while(index >= 0){
       max_heapify(intVector,index);
       index--;
   }
   return;
}

/* 
    Recursive equation of Time Complexity is :
         T(n) = T(2n/3) + 0(1)
      => T(n) = O(lg n) ( By Master Theorem )
*/
void max_heapify(std::vector<int>& intVector,int index){
    auto l = left(index);
    auto r = right(index);
    auto largest = -1;
    
    if( l < heapSize && intVector.at(l) > intVector.at(index)){
        largest = l;
    }else{
        largest = index;
    }
    
    if( r < heapSize && intVector.at(r) > intVector.at(largest)){
        largest = r ;
    }
    
    if ( largest != index ){
        std::swap(intVector[index],intVector[largest]);
        max_heapify(intVector,largest);
    }

    return;
}

/*
    Time Complexity : O(n lgn)
*/
std::vector<int> heap_sort(std::vector<int>& intVector){
    
    heapSize = intVector.size();
    build_max_heap(intVector);
    

    if(heapSize < 2 )
        return intVector ;

    for(int i = heapSize-1 ; i !=0 ; i--){
        std::swap(intVector[i],intVector[0]);
        heapSize-- ;
        max_heapify(intVector,0);
    }
    return intVector;
}
