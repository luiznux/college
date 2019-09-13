#include "node.h"

Node::Node(float item, Node *new_node){

    valor = item;
    next = new_node;
}

Node::~Node(){
}
