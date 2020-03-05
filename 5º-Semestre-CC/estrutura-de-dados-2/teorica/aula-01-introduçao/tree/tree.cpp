#include "tree.h"

/*
  Construdor da classe arvore, cria uma arvore com raiz nula
 */
tree::tree(){
    root = NULL;
}

/*
  metodo para inserir um valor na arvore, utilizado quando sua raiz é  vazia
 */
void tree::insert(int value){

    //verifica se a raiz esta vazia
    if(root == NULL)
        root = new node(value); //crio uma raiz vazia

    else
        insert(root, value); //chamada recursiva da função abaixoo
}

/*

 */
void tree::insert(node *node, int value){

    //se o valor a ser inserido vor menor que  o valor presente no nó atual
    if(value < node->get_data()){

        //verifica se o nó da esquerda é nulo
        if(node->get_left() == NULL){
            node new_dode = new node(value);
        }
    }
}
