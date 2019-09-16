/*
         Prim's Algorithm for obtaining MST 

         This is an example run :
             Enter Number of vertices in the graph: 7
             Enter Number of edges in the graph: 12
             Now enter edges in  follwing format
             "node_1 node_2 edge_weight"
            1 2 4
            1 3 8
            2 3 9
            2 4 8
            3 4 2
            2 5 10
            3 6 1
            4 5 7
            4 6 9
            5 6 5
            5 7 6
            6 7 2
            Enter start Node: 1
             { (1,2),(1,3),(3,6),(3,4),(6,7),(6,5), }
            The weight of the minimum spanning  tree is : 22
*/

/*
*****************************************************************************
WHY PRIM'S AND KRUSKAL ALGORITHM CANT BE USED FOR DIRECTED GRAPH ? :
Prim's fails because it assumes, every node is reachable from every node which 
 though valid for undirected graphs may not be true for digraphs. Kruskal fails because 
 of failure to detect cycles and sometimes it is essential to add edges making cycles to
  satisfy "minimum"  weighted property of MST.
 ****************************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    struct neighbour_node
    {
        // information to be stored about the neighbour of the node
        int node;   // node ID
        int weight; // weight of the edge
    };

    int total_vertices;                 // total nodes in the graph
    map<int, list<neighbour_node>> adj; // container to map every node to its adjacency list

public:
    Graph(int n) : total_vertices(n){}; // constructor

    void insertEdge(int node1, int node2, int weight)
    {
        /*
            This function add (dest_node,weight) into the adjacency list of
            start_node
        */
        struct neighbour_node tmp1;
        tmp1.node = node2;
        tmp1.weight = weight;
        adj[node1].push_back(tmp1);

        struct neighbour_node tmp2;
        tmp2.node = node1;
        tmp2.weight = weight;
        adj[node2].push_back(tmp2);
        return;
    }

    list<neighbour_node> get_neigh_list(int u)
    {
        // function returning information about the adjacent nodes of u
        return adj[u];
    }
};

struct edge
{
    int node1;
    int node2;
    int wt;
};

/*
We need a MIN PRIORITY QUEUE for this algorithm. ( for efficient implementation )
But the c++ STL does not directly provide this facility . So we need a comparator to
use the generic container priority_queue as the min priority queue.
*/
class myComparator
{
public:
    int operator()(const edge &e1, const edge &e2)
    {
        return e1.wt > e2.wt;
    }
};

int main(void)
{

    int n, en;
    cout << " Enter Number of vertices in the graph: ";
    cin >> n;
    cout << " Enter Number of edges in the graph: ";
    cin >> en;

    Graph g(n);
    cout << " Now enter edges in  follwing format \n \"node_1 node_2 edge_weight\"" << endl;
    for (int i = 0; i < en; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.insertEdge(u, v, w);
    }

    cout << " Enter start Node: ";
    int s;
    cin >> s;

    priority_queue<edge, vector<edge>, myComparator> mpq;
    set<int> explored_set;
    explored_set.insert(s);
    vector<edge> mst_edges;

    for (auto elem : g.get_neigh_list(s))
    {
        mpq.push({s, elem.node, elem.weight});
    }

    for (int i = 1; i <= n - 1; i++)
    {
        edge e;
        /* We need to select that edge which has one node in our explored set and
         other node in our unexplored set.
         */
        do
        {
            e = mpq.top();
            mpq.pop();
        } while (explored_set.find(e.node1) != explored_set.end() &&
                 explored_set.find(e.node2) != explored_set.end());

        mst_edges.push_back(e);

        // Determine that  node of the edge  which is not our explored set
        int newNode;
        if (explored_set.find(e.node1) != explored_set.end()){
            newNode = e.node2;
        }
        else {
            newNode = e.node1;
        }

        // explore the new node that is added along with this edge
        for (auto elem : g.get_neigh_list(newNode))
        {
            mpq.push({newNode, elem.node, elem.weight});
        }

        // add it to the explored set
        explored_set.insert(newNode);
    }

    int wt = 0;
    cout << " { ";
    for (auto elem : mst_edges)
    {
        cout << "(" << elem.node1 << "," << elem.node2 << "),";
        wt += elem.wt;
    }
    cout << " }\n";
    cout << "The weight of the minimum spanning  tree is : ";
    cout << wt << endl;
}
