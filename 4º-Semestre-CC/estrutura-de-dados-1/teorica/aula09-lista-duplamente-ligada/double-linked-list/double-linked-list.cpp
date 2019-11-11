#include "double-linked-list.h"

Double_linked_list::Double_linked_list(){

    head = NULL;
    tail = NULL;
}

Double_linked_list::~Double_linked_list(){}

bool Double_linked_list::IsEmpty(){

    return head == NULL;
}

bool Double_linked_list::Insert(float value){

    Node *new_node;
    new_node = new Node(value,NULL,NULL);

}

bool  Double_linked_list::Insert_start(float value){

}

bool Double_linked_list::Insert_end(float value){}

bool Double_linked_list::Remove_first(){}

bool Double_linked_list::Remove_last(){}

bool Double_linked_list::Remove_value(float value){}

bool Double_linked_list::Is_in_List(float value){}

void Double_linked_list::print_List(){}

void Double_linked_list::inverse_print_List(){}
