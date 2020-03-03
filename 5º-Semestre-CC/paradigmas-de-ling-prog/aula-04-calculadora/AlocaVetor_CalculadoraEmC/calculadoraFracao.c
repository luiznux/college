/*
Escreva um programa que tenha uma funcao que aloca o vetor e
preenchê-lo com zeros;

o programa principal mostra o vetor preenchido


*/
#include <stdio.h>
#include <stdlib.h>

// tipo fracao
typedef struct{
    int num, den;
}TFracao;

TFracao * soma( TFracao *f1, TFracao *f2 ){

    TFracao * f = (TFracao*) calloc(1, sizeof(TFracao));
    //(a/b)+(c/d)=( (a.d+c.b) / b.d )
    f->num = f1->num*f2->den + f2->num*f1->den;
    f->den = f1->den*f2->den;

    f1->num = 10;
    return f;
}

// funcao cliente que testa as operacaoes da calculdora
int main(){

    TFracao *f1, *f2, *f3;
    f1 = (TFracao*) calloc(1, sizeof(TFracao));
    f2 = (TFracao*) calloc(1, sizeof(TFracao));

    f1->num = 2; // (*f1).num = 2
    f1->den = 3;
    f2->num = 1;
    f2->den = 4;
    f3 = soma( f1, f2);
    printf("f3=%d/%d\n",f3->num, f3->den);

    printf("f1=%d/%d\n",f1->num, f1->den);
    free(f1);
    free(f2);
    free(f3);

    return 0;
}
