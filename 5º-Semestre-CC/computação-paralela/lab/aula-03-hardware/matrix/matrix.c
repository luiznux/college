#include <stdio.h>
#include <stdlib.h>


/*
  Função para alocar dinamicamente uma matriz de tamanho dados como parametros linhas(line) e colunas(colum)
  A função retorna um ponteiro para uma matriz
 */
int **calloc_matrix(int line, int colum){

    //ponteiro para a matriz
    int** matrix;

    //aloco as linhas
    matrix = (int **) calloc (line,sizeof(int *));

    //aloco as colunas
    for(int l = 0; l < line; l++){
        matrix[l] = (int*) calloc(colum,sizeof(int));
    }
    return matrix;
}


/*
  Função para imprimir uma matriz, recebe o ponteiro para a matriz(matrix), sua linha e coluna.
  Caso a matriz dada seja maior que 8(linhas ou colunas), nao sera possivel imprimir
 */
int print_matrix(int **matrix,int line, int colum){

    //caso a matriz for muito grande, nao dou print
    if(line >=  8 || colum >= 8){
        printf("Cannot print!!!");
        return -1;

    }for(int l = 0; l < line ; l++){
        printf("\n [ ");
        for(int c = 0; c < colum; c++){
            printf("%d ",matrix[l][c]);
        }
        printf("]");
    }
    printf("\n\n");
    return 0;
}
