#include "pilha.h"


Stack::Stack(){

    top_stack = NULL;
}

bool Stack::empty(){
    if(top_stack == NULL)
        return true;
}

bool Stack::push(int item){

    Node novo_top =  new Node(item,topo);
}


bool Stack::pop(){

    //armazeno o endereço do antigo topo
    Node *old_top = top_stack;

    if(top_stack == NULL)

}
