#include <iostream>
#include <vector>
#include <cmath>


void max_heapify(std::vector<int>& intVector,int index);
void build_max_heap(std::vector<int>& intVector);
std::vector<int> heap_sort(std::vector<int>& intVector);
int parent(int index) ;
int left  (int index) ;
int right (int index) ;