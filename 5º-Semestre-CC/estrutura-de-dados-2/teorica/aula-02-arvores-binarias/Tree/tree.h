#ifndef TREE_H
#define TREE_H
#include "node.h"

class Tree : public Node
{

private:

    Node *root;

public:

    Tree();
    Node *get_root();
//    Tree *get_left();
//    Tree *get_righti();
    bool is_null(Node tree);
    int counter(Node tree);
    void min_value();
    void max_value();
    bool locate_value(int value);
    void insert(int value);
    void insert(Node *node, int value);
    void print_in_order(Node *node);
    void print_in_pre_order(Node *node);
    void print_pos_order(Node *node);

};
#endif
