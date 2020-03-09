#ifndef TREE_H
#define TREE_H
#include "node.h"

class Tree
{

private:

    Node *root;

public:

    Tree();
    Node *get_root();
    int counter();
    void min_value();
    void max_value();
    void locate_value(int value);
    void insert(int value);
    void insert(Node *node, int value);
    void print_in_order(Node *node);
    void print_in_pre_order(Node *node);
    void print_pos_order(Node *node);

};
#endif
