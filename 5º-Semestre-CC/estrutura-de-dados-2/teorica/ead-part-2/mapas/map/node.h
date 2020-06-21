#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "value.h"

/*
  Classe que armazena os dados do carro e recebe sua chave(placa) como string
  Usando um nó para armazenar os valores
 */
struct Node{

// data members
    Node *next;
    char placa[tam];
    Value *carro;

// constructors
	Node(Node *next, char *placa, Value *carro)
    {
        this->next = next; strcpy(this->placa, placa); this->carro = carro;
    }

	Node(char *placa, Value *carro)
    {
        this->next = NULL ; strcpy(this->placa, placa); this->carro = carro;
    }

};
#endif
