#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{

private:
    Node *left, *right;
    int data;

public:
    Node();
    Node(int data);
    int get_data();
    Node *get_left();
    Node *get_right();
    void set_left(Node *node);
    void set_right(Node *node);

    friend class Tree;
};
#endif
