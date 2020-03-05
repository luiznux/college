#include "node.h"

/*
  Construtor da classe node, recebe um valor inteiro e cria um nó com o valor inserido, juntamente com as duas direções(esq e dir) definidas como nulo
 */
node::node(int data){

    this->data = data;
    left = right = NULL;
}

/*
  Metodo para consultar o valor do atributo "data"
 */
int node::get_data(){
    return data;
}

/*
  metodo para consultar o atributo left
 */
node* node::get_left(){
    return left;
}

/*
  metodo para consultar o atribbuto right
 */
node* node::get_right(){
    return right;
}

/*
  metoodo que faz com que o atributo(left) do nó atual aponte para um outro nó
 */
void node::set_left(node *node){
    left = node;
}

/*
  metodo que faz com que o atributo(right) do nó atual aponte para um outro nó
 */
void node::set_right(node *node){
    right = node;
}
