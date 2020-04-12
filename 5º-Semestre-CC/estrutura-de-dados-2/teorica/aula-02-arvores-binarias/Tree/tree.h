#ifndef TREE_H
#define TREE_H
#include "node.h"

class Tree
{

private:

    Node *root;
    int count_nodes(Node *);


    public:

    Tree();
    Node *get_root();
    bool is_null();
    int count(Node node);
    int min_value();
    int max_value();
    bool locate_value(int value);
    void insert(int value);
    void insert(Node *node, int value);
    void print_in_order(Node *node);
    void print_in_pre_order(Node *node);
    void print_pos_order(Node *node);
};
#endif
