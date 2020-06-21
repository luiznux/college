#ifndef VALUE_H
#define VALUE_H
#include <string.h>
const int tam = 10;

/*
  Classe para armazenar os valores de um carro, recebendo as strings e seu ano
 */
struct Value{

    char modelo[tam];
    char cor[tam];
    int  ano;

    /* copio os parametros para os respectivos atributos */
    Value(char *modelo, char *cor,int ano){
        strcpy(this->modelo, modelo); strcpy(this->cor, cor);
        this->ano = ano;
    }
};
#endif
