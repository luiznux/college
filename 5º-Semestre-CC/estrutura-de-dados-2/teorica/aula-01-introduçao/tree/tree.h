#ifndef TREE_H
#define TREE_H
#include "node.h"

class tree
{

private:

    node *root;

public:

    tree();
    void insert(int value);
    void insert(node *node, int value);
    node *get_root();
    void print_in_order(node *node);
    void print_in_pre_order(node *node);
    void print_pos_order(node *node);

};
#endif
