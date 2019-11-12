#include <stdio.h>

// vetor das moedas
int vector[6][2] = {{1, 0}, {5, 0}, {10, 0}, {25, 0,}, {50, 0}, {100, 0}};
int size1 = 6;
int size2 = 2;

// moedas disponivieis {0.01, 0.05, 0.10, 0.25, 0.50, 1.00}

// o segundo vetor é  a quantidade de trocos

/*
 *o Problema consiste em dar o melhro troco possivel para uma quantidade
 *de moedas que possuo
 */
void troco(float value)
{
    //converto o valor dado para inteiro para vacilitar o calculo
    int new_value = (int) (value * 100);

    for (int i = 5; new_value != 0;) {
        // o troco ainda da
        if (vector[i][0] <= new_value){
            new_value = new_value - vector[i][0];
            vector[i][1] = vector[i][1] + 1;
        } else {
            i--;
        }
    }
}

void print_vector()
{
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", vector[i][j]);
        }
        printf(", ");
    }
    puts("");
}


int main()
{
    float dinheiro = 2.89;

    print_vector();

    troco(dinheiro);

    print_vector();

    return 0;
}
