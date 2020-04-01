#include "node.h"

Node::Node(){
    left = right = NULL;
}
/*
  Construtor da classe node, recebe um valor inteiro e cria um nó com o valor inserido, juntamente com as duas direções(esq e dir) definidas como nulo
 */
Node::Node(int data){

    this->data = data;
    left = right = NULL;
}

/*
  Metodo para consultar o valor do atributo "data"
 */
int Node::get_data(){
    return data;
}

/*
  metodo para consultar o atributo left
 */
Node* Node::get_left(){
    return left;
}

/*
  metodo para consultar o atribbuto right
 */
Node* Node::get_right(){
    return right;
}

/*
  metoodo que faz com que o atributo(left) do nó atual aponte para um outro nó
 */
void Node::set_left(Node *node){
    left = node;
}

/*
  metodo que faz com que o atributo(right) do nó atual aponte para um outro nó
 */
void Node::set_right(Node *node){
    right = node;
}
