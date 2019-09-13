#ifndef PILHA_H
#define PILHA_H
#include "node.h"
class Stack{

private:
    Node *top_stack;


public:

    Stack();
    ~Stack();
    bool empty();
    bool push(int item);
    bool pop();
    bool top(int &item);
    void print();
};

#endif
