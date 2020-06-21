#include  "map.h"

Map::Map(){
     head = NULL;
}

Map::~Map(){}

bool Map::are_strings_equal(char *str1, char *str2){
    int result = strcmp(str1, str2);
    if (!result) return true;
    return false;
}


bool Map::insertMap(Node *car){

    Node *aux = head;

    while( aux->next != NULL ){
        if(are_strings_equal(car->placa, aux->placa)) return false;
        aux = aux->next;
    }

    aux->next = new Node(aux->next,car->placa,car->carro);
    return true;
}

bool Map::searchValue(char *placa){

    Node *aux = head;

    while(aux != NULL){
        if(are_strings_equal(placa, aux->placa)){
            return true;
        }
        aux = aux->next;
    }
    return false;
}
