#include "max_prior_q.h"


int heap_maximum(std::vector<int>& heap) { return heap.at(0); }

int heap_extract_max(std::vector<int>& heap)
{
    try{
        if( heap.size() < 1){
            throw std::runtime_error{"heap is empty"};
        }else{
            auto max = heap[0];
            heap.at(0) = heap.at(heap.size()-1);
            heap.pop_back();
            max_heapify(heap,0);
            return max;
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}


void heap_increase_key(std::vector<int>& heap,int index,int key){

    try{
        if( key < heap.at(index))
            throw std::runtime_error{"new key is smaller than the current key"};
        heap.at(index) = key;
        while( index > 0 && heap.at(parent(index)) < heap.at(index) ){
            std::swap(heap[parent(index)],heap[index]);
            index = parent(index);
        }
    }
    catch(std::exception& e){
        std::cerr << e.what() <<"\n" ;
    }
}

void max_heap_insert(std::vector<int>& heap,int key){
    heap.push_back(INT32_MIN);
    heap_increase_key(heap,heap.size(),key);
}

