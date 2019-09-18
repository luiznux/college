#include "pilha.h"

int main(){

    Pilha coisa = Pilha();

    float x = 300;

    float y = 500;

    coisa.push(x);
    coisa.push(y);

    coisa.imprime();



    return 0;

}
