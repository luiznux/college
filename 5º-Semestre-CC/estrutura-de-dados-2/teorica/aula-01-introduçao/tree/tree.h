#ifndef TREE_H
#define TREE_H
#include "node.h"

class Tree
{

private:

    Node *root;

public:

    Tree();
    void insert(int value);
    void insert(Node *node, int value);
    Node *get_root();
    void print_in_order(Node *node);
    void print_in_pre_order(Node *node);
    void print_pos_order(Node *node);

};
#endif
