/* 
    Implementation of the DIJKSTRA ALGORITHM 
*/

#include <bits/stdc++.h>
#define MAX_VAL INT32_MAX
using namespace std;

/*
    This graph class will store the graph as the adjacency list representation
    
*/
class DirectedGraph {
    struct neighbour_node {   
        // information to be stored about the neighbour of the node
         int node;      // node ID
         int weight;    // weight of the edge
    };
    
    int total_vertices ;            // total nodes in the graph
    map<int,list<neighbour_node>> adj;  // container to map every node to its adjacency list
    
    public:

    DirectedGraph(int n):total_vertices(n){};   // constructor

    void insertEdge (int start_node,int dest_node,int weight) { 
        /*
            This function add (dest_node,weight) into the adjacency list of
            start_node
        */
        struct neighbour_node tmp;
        tmp.node = dest_node;
        tmp.weight = weight;
        adj[start_node].push_back(tmp);
        return;
    }

    list<neighbour_node> get_neigh_list(int u){
        // function returning information about the adjacent nodes of u
        return adj[u];
    }
};


 class node_info {  
     /*
     During the exploration of graph , we need to store the information about 
     the parent pf a node and the current shortest distance to this point
     from the source node.
     */
     public:
        int node_no;
        int parent;
        int distance;
};

/*
We need a MIN PRIORITY QUEUE for this algorithm. ( for efficient implementation )
But the c++ STL does not directly provide this facility . So we need a comparator to
use the generic container priority_queue as the min priority queue.
*/
class myComparator {
    public:
    int operator() ( const node_info& u,const node_info& v){
        return u.distance > v.distance;
    }
};

/*
This is dijkstra algorithm specific class.
the main container in this class are :
1. map_nodeInfo : this mapping maps all the nodes to its information 
                i.) its Node Id
                ii.) its current estimated shortest distance from the start node 
                iii.) the parent from which its current path come through
2. visited_vertices :
                This stores the NODE IDs of all the nodes which has been explored 
3. Q :
                This is the min-priority-queue required
*/
class dijkstra_specific {
   
    int start_node ;
    int total_vertices;
    map<int,node_info> map_nodeInfo;
    priority_queue<node_info,vector<node_info>,myComparator> Q;
    set<int> visited_vertices;

    public:
    dijkstra_specific(int n){
        total_vertices = n ; 
    }

    void initialize_single_source(int s){
        start_node  = s;
        for(int i = 1 ; i <= total_vertices ; i++){
            map_nodeInfo[i].node_no = i;
            map_nodeInfo[i].parent = 0 ; 
            map_nodeInfo[i].distance = MAX_VAL;
        }
        map_nodeInfo[s].parent = 0; 
        map_nodeInfo[s].distance = 0;
    }

    int get_distance(int u){
        return map_nodeInfo[u].distance;
    }

    void build_min_prior_q(){
        //reset the queue
        while( !Q.empty()){
            Q.pop();
        }
        //build it again
        for(int i=1 ; i <= total_vertices ; i++){
            if(visited_vertices.find(map_nodeInfo[i].node_no) == visited_vertices.end()){
                Q.push(map_nodeInfo[i]);
            }   
        }
        return;
    }

    bool is_Q_empty(){
        return Q.empty();
    }

    int extract_Q(){
        auto min = Q.top();
          // Add the top node from min-priority-queue to the visited vertices and
         //  remove this from the queue 
        visited_vertices.insert(min.node_no);
        Q.pop();      
        if( min.distance != MAX_VAL ){
            return min.node_no;
        } else {
            return -1;
        }
    }
    
    // The relax function is describe in the book itself refer it
    void relax(int u,int v, int w){
        if ( map_nodeInfo[v].distance > map_nodeInfo[u].distance + w){
            map_nodeInfo[v].distance = map_nodeInfo[u].distance + w ;
            map_nodeInfo[v].parent = u;
        }
        return;
    }   
};


int main(int argc,char** argv){

  int n,en;
  cout << " Enter Number of vertices in the graph: "  ;
  cin >> n ;
   cout << " Enter Number of edges in the graph: "  ;
  cin >> en ;


  DirectedGraph dg(n);
  dijkstra_specific dj(n);

  cout << " Now enter edges in  follwing format \n \"start_node dest_node edge_weight\"" << endl;
  for(int i = 0 ; i < en ; i++){
      int u,v,w;
      cin >> u >> v >> w;
      dg.insertEdge(u,v,w);
  }

  cout << " Enter start Node: " ;
  int s;
  cin >> s;
  dj.initialize_single_source(s);
  dj.build_min_prior_q();

  cout << " ---------------------------------------------------" <<endl;
  cout << " From node " << s << endl; 
  
  while( !dj.is_Q_empty() ){
     // cout << " in while loop" << endl;
      int u = dj.extract_Q();
      /* 
        if every other node is at infinite distance , then they are not
        reachable from the start node.
        At this poing we need to quit the loop.
        @ Think what you should do if the graph is undirected @
        */
      if ( u == -1){ break; }   
      cout << " TO NODE  Shorest  Distance" << endl; 
      cout << "  " << u << "     :          " << dj.get_distance(u) << endl ;
      auto neighbour_list = dg.get_neigh_list(u);
      for(auto itr = neighbour_list.begin() ; itr != neighbour_list.end() ; itr++){
          dj.relax(u,itr->node,itr->weight);
      }
      /* we have remove a node from the min-priority-queueu during extraction of 
         queue ,  so we MUST rebuild the queue again ( read about the heap data structure)
       */
      dj.build_min_prior_q();
  }
  cout << " ---------------------------------------------------" <<endl;
  return 0;
}


