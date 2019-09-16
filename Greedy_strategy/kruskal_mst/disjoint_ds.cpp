#include <map>
#include <iostream>
#include "disjoint_ds.hpp"

Node::Node(long long int label){
    this->label = label;
    this->children_count = 1 ; // initially a node is child of itself
    this->parent = this;
}

bool Node::isRoot(){
    return (this == this->parent);
}

Node* Node::get_parent(){
    return this->parent;
}
void Node::set_parent(Node* parent){
    this->parent = parent;
}

long long Node::get_child_count(){
    return this->children_count ;
}

long long Node::get_label(){
    return this->label ;
}

void Node::set_child_count(long long count){
    this->children_count = count;
}

disjoint_ds::disjoint_ds(long long first_node_label, long long n)
{
    this->n = n;
    this->total_set_count = n;
    long long last_node_label = first_node_label + n - 1;
    for (long long i = first_node_label; i <= last_node_label; i++)
    {
       create_set(i);
    }
}

void disjoint_ds::create_set(long long x){
 Node *node = new Node(x);
        map_label_to_node[x] = node;
}

long long disjoint_ds::find_set(long long x){
    Node* tmpNode;
    tmpNode = map_label_to_node[x];
  //  long long c = 0;
    while( tmpNode->get_parent() != tmpNode){
  //      c++;
        tmpNode = tmpNode->get_parent();
    }
//    std::cout << "total_steps : " << c << std::endl;
    return tmpNode->get_label();
}

/* Use the technique of UNION-BY-RANK */
void disjoint_ds::union_set(long long x1,long long x2){
    
    auto p1 = find_set(x1);
    auto p2 = find_set(x2);

    if( p1 == p2 ){ // the nodes are already in same set
        return; 
    }

    if( map_label_to_node[p1]->get_child_count() >= map_label_to_node[p2]->get_child_count() ){
        map_label_to_node[p2]->set_parent(map_label_to_node[p1]->get_parent());
        map_label_to_node[p1]->set_child_count( map_label_to_node[p2]->get_child_count() \
                                                + map_label_to_node[p1]->get_child_count());

    } else {
        map_label_to_node[p1]->set_parent(map_label_to_node[p2]->get_parent());
         map_label_to_node[p2]->set_child_count( map_label_to_node[p2]->get_child_count() \
                                                + map_label_to_node[p1]->get_child_count());
    }
    return;
}
