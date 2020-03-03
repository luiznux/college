/*
Escreva um programa que tenha uma funcao que aloca o vetor e
preenchê-lo com zeros;

o programa principal mostra o vetor preenchido


*/
#include <stdio.h>
#include <stdlib.h>

void alocaVetor( int **vetor, int N){
    // aloca e preenche com zeros
    *vetor = (int*) calloc( N, sizeof(int));
}
int main(){
    int tam,i;
    int *vetor;// vetor alocado dinamicamente
    printf("digite o tamanho do vetor:");
    scanf("%d",&tam);

    alocaVetor(&vetor,tam);

    for(i=0;i<tam;i++){
        printf("%d ",vetor[i]);
    }
    free(vetor);
    return 0;
}
