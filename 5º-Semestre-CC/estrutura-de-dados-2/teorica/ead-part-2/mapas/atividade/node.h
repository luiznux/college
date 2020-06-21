#ifndef NODE_H
#define NODE_H
#include <string.h>
#include "value.h"
#include <iostream>

struct Node
{
// data members
    Node *next;
    char *placa;
    Value carro;

// constructors
	Node(Node *ptr, char placa[tam], Value carro)
    {
        ptr = NULL;
    }
};
#endif
