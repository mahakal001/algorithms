#include <bits/stdc++.h>
#include "disjoint_ds.hpp"
/*
WHY PRIM'S AND KRUSKAL ALGORITHM CANT BE USED FOR DIRECTED GRAPH ? :

 Prim's fails because it assumes, every node is reachable from every node which 
 though valid for undirected graphs may not be true for digraphs. Kruskal fails because 
 of failure to detect cycles and sometimes it is essential to add edges making cycles to
  satisfy "minimum"  weighted property of MST.
*/
/*
    TC = O(elog e) = O( e log v)
*/

struct edge {
    long long n1;
    long long n2;
    long long wt;
};
// Compares two struct according to weight. 
bool myComparator(edge e1,edge e2) 
{ 
    return (e1.wt <= e2.wt); 
} 

/* 
    v_count: number of vertices in the graph
    e_count : number of edges in the graph
    edges : contain a vector of elements of struct edge
*/
void kruskal_mst(std::vector<edge>& edges,int v_count,int e_count){
    
    std::sort(edges.begin(),edges.end(),myComparator); // O(e (log e))

    disjoint_ds d_ds(1,v_count); // O(v)

    std::vector<edge> mst_edges;

    for( int i = 0 ; i < e_count ; i++ ){

        if( d_ds.find_set(edges[i].n1) != d_ds.find_set(edges[i].n2) ){
             // Because we use UNION-BY-RANK , so find operation take O(log v)
             //in worst case.
             //  Time Complexity of this loop :  O(e log v)
            mst_edges.push_back(edges[i]);
            d_ds.union_set(edges[i].n1,edges[i].n2);
        }

        if( mst_edges.size() == (v_count-1) ){
            break;
        }
    }

    long long wt = 0;
    std::cout << " { ";
    for (auto elem : mst_edges)
    {
        std::cout << "(" << elem.n1 << "," << elem.n2 << "),";
        wt += elem.wt;
    }
    std::cout << " }\n";
    std::cout << "The weight of the minimum spanning  tree is : ";
    std::cout << wt << std::endl;

return ;

}

int main(void){

    std::cout << "Enter the number of Vertices: ";
    long long v;
    std::cin >> v;
    std::cout << " Enter the number of edges : " ;
    long long edge_count;


    std::cin >> edge_count;
    std::vector<edge> edges; 
    long long tmp_node1,tmp_node2,tmp_wt;
    for( int i = 0 ; i < edge_count ; i++){
        std::cin >> tmp_node1 >> tmp_node2 >> tmp_wt ;
        edges.push_back({tmp_node1,tmp_node2,tmp_wt});
    }

    kruskal_mst(edges,v,edge_count);
    return 0;

}