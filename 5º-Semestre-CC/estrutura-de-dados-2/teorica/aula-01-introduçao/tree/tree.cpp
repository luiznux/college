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

            class node *new_node = new class node(value);
            node->set_left(new_node); //seto um novo nó para a esquerda

        } else {

        //caso contrario, vou continuar percorrendo(recursivamente) ate encontrar um
        // nó a esquerda que esteja nulo
        insert(node->get_right(), value);
        }

        //se o valor a ser inserido for maior doq o do nó atual
    } else if(value > node->get_data()){

        //verifica se o nó da direta é nulo
        if(node->get_right() == NULL){

            class node *new_node = new class node(value);
            node->set_right(new_node); //seto o novo nó na direita

        } else {
            //caso contrario, continuo percorrendo ate encontrar um nó da direita
            //que seja nulo
            insert(node->get_right(), value);
        }
    }
    //se for igaul, nao sera possivel inserir, pois nao pode existir 2 values =
}


/*
  Metodo para consultar a raiz da arvore
 */
node* tree::get_root(){

    return root;
}

void tree::print_in_order(node *node){

    if(node != NULL){
        print_in_order(node->get_left());
        std::cout << node->get_data() << " ";
        print_in_order(node->get_right());
    }
}


void tree::print_in_pre_order(node *node){

    if(node != NULL){
        std::cout << node->get_data() << " ";
        print_in_order(node->get_left());
        print_in_order(node->get_right());
    }
}

void tree::print_pos_order(node *node){

    if(node != NULL){
        std::cout << node->get_data() << " ";
        print_in_order(node->get_left());
        print_in_order(node->get_right());
    }
}
