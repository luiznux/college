#ifndef NODE_H
#define NODE_H
#include <iostream>

class node
{

private:
    node *left, *right;
    int data;

public:

    node(int data);
    int get_data();
    node *get_left();
    node *get_right();
    void set_left(node *node);
    void set_right(node *node);

};
#endif
