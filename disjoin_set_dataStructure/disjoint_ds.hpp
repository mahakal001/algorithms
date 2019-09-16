#include <map>

class Node
{
        long long children_count;
        long long label;
        Node* parent;

        public :

        Node(long long int);
        long long get_label();
        bool isRoot();
        Node* get_parent();
        void set_parent(Node* parent);
        long long get_child_count();
        void set_child_count(long long);

};

class disjoint_ds{

       long long n ; // total nodes in the disjoint set
        long long total_set_count ;
        std::map<long long int,Node*>  map_label_to_node;
        

        public :

        disjoint_ds(long long  first_node_label , long long n);
        void create_set(long long x);
        void union_set(long long x1,long long x2);
        long long find_set(long long x);
};





