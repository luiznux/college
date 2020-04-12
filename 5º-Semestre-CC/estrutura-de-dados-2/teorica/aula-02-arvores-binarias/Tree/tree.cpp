#include "tree.h"

/*
 Construdor da classe arvore, cria uma arvore com raiz nula
 */
Tree::Tree(){
    root = NULL;
}

/*
  Metodo para consultar a raiz da arvore
 */
Node* Tree::get_root(){
    return root;
}


/*
  metodo para consutar se a raiz é nula, retornando um booleano
 */
bool Tree::is_null(){
    return root == NULL;
}


/*
  Metodo para contar quantos elementos a arvore possui, retornando um inteiro
  como resultado
 */
int Tree::count_nodes(Node *node){

    //verifica se é nula(condição de parada)
    if(node == NULL) return 0;

    int counter = 0;

	counter = 1+ count_nodes(node->get_left()) + count_nodes(node->get_right());

    return counter;
}


/*
  encontra e retorna o menor valor
  percorro  arvore ate o nó mais a esquerda
 */
int  Tree::min_value(){

    if(this->root == NULL) return -1;
    Node *aux;
    aux = this->root;
    while(aux->left != NULL){
        aux = aux->left;
    }
    return aux->data;
}


/*
  encontra e retorna o maior valor
  percorro a arvore ate o nó mais a direta
 */
int  Tree::max_value(){

    if(this->root == NULL) return -1;
    Node *aux;
    aux = this->root;
    while(aux->right != NULL){
        aux = aux->left;
    }
    return aux->data;
}


/*
  Metodo para verificar se o valor dado como parametro esta ou nao na arvore
  retornando um booleano
 */
bool Tree::locate_value(int value){

    Node *aux = root;
    //verifico se o proximo da esquerda/direta é nulo
    while(aux != NULL){
        if(aux->data < value){
            aux = aux->left;

        }else if(aux->data > value){
            aux = aux->right;

        }else{
            return true;
        }
    }
    return false;
}

/*
  Metodo para inserir em uma arvore binária caso a mesma não se encontre vazia
  Utiliza-se o metodo de inserção de uma arvore binaria
 */
void Tree::insert(Node *node, int value){

    //se o valor a ser inserido for menor que o valor presente no nó atual
    if(value < node->get_data()){

        //verifica se o nó da esquerda é nulo
        if(node->get_left() == NULL){

            Node *new_node = new Node(value);
            node->set_left(new_node); //seto um novo nó para a esquerda

        } else {

        //caso contrario, vou continuar percorrendo(recursivamente) ate encontrar um
        // nó a esquerda que esteja nulo
        insert(node->get_left(), value);
        }

        //se o valor a ser inserido for maior doq o do nó atual
    } else if(value > node->get_data()){

        //verifica se o nó da direta é nulo
        if(node->get_right() == NULL){

            Node *new_node = new Node(value);
            node->set_right(new_node); //seto o novo nó na direita

        } else {
            //caso contrario, continuo percorrendo ate encontrar um nó da direita
            //que seja nulo
            insert(node->get_right(), value);
        }
    }
    //se for igual, nao sera possivel inserir, pois nao pode existir 2 values =
}


/*
  metodo para inserir um valor na arvore, utilizado quando sua raiz é  vazia
 */
void Tree::insert(int value){

    //verifica se a raiz esta vazia
    if(root == NULL)
        root = new Node(value); //crio uma raiz vazia

    else
        insert(root, value); //chamada recursiva da função abaixoo
}


/*
  esquerda raiz direita
 */
void Tree::print_in_order(Node *node){

    if(node != NULL){
        print_in_order(node->get_left());
        std::cout << node->get_data() << " ";
        print_in_order(node->get_right());
    }
}

/*
  raiz esquerda direta
 */
void Tree::print_in_pre_order(Node *node){

    if(node != NULL){
        std::cout << node->get_data() << " ";
        print_in_order(node->get_left());
        print_in_order(node->get_right());
    }
}


/*
  esquerda direta raiz
*/
void Tree::print_pos_order(Node *node){

    if(node != NULL){
        std::cout << node->get_data() << " ";
        print_in_order(node->get_left());
        print_in_order(node->get_right());
    }
}
