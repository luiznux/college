#include "double-linked-list.h"


Double_linked_list::Double_linked_list(){

    head = tail = NULL;
}

Double_linked_list::~Double_linked_list(){}


bool Double_linked_list::IsEmpty(){

    return head == NULL;
}

//insere no final(depois do tail)
bool Double_linked_list::Insert(float value){

    //verifica se nao está vazia e insiro o primeiro elemente
    if(IsEmpty()){
        Node *new_node = new Node(value,NULL,NULL);
        head = tail = new_node;
        return true;
    }
    Node *aux;
    for(aux = head; aux->next != NULL; aux = aux->next){
    }
    aux->next = new Node(value,aux,NULL);
    tail = aux->next;
    return true;
}

bool  Double_linked_list::Insert_start(float value){

    //verifica se nao está vazia e insiro o primeiro elemente
    if(IsEmpty()){
        Node *new_node = new Node(value,NULL,NULL);
        head = tail = new_node;
        return true;
    }

    head->preview = new Node(value,NULL,head);
    head = head ->preview;
    return true;
}

bool Double_linked_list::Insert_end(float value){

    //verifica se nao está vazia e insiro o primeiro elemente
    if(IsEmpty()){
        Node *new_node = new Node(value,NULL,NULL);
        head = tail = new_node;
        return true;
    }

    tail->preview = new Node(value,tail,NULL);
    tail = tail->next;
    return true;
}

bool Double_linked_list::Remove_first(){

    Node *aux = head->next;
    delete head;
    head = aux;
    return true;
}

bool Double_linked_list::Remove_last(){

    Node *aux = tail->preview;
    delete tail;
    tail = aux;
    return  true;

}

bool Double_linked_list::Remove_value(float value){

    for(Node *aux = head; aux->next != NULL; aux = aux->next){
        if(aux->item == value){
            aux->preview->next = aux->next;
            delete aux;
        }
    }
    return true;
}

bool Double_linked_list::Is_in_List(float value){

    for(Node *aux = head; aux->next != NULL; aux = aux->next){
        if(aux->item ==value)break ;
    }
    return  true;
}

void Double_linked_list::print_List(){

    for(Node *aux = head; aux->next != NULL; aux = aux->next){
        std::cout << aux->item << " "<< std::endl;
    }
}

void Double_linked_list::inverse_print_List(){

    for(Node *aux = tail; aux->preview != NULL; aux = aux->preview){
        std::cout << aux->item << " "<< std::endl;
    }
}
