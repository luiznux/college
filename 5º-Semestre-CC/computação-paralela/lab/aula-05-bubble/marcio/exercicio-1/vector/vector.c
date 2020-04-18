#include "vector.h"


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
  Preenche dois vetores com numeros aleatorias atrelados a uma semente
  dada como parametro
 */
void fills_rand_vector(int **vector, int line, int colum, int value){
    for(int i = 0; i < line; i++){
        for(int j = 0; j < colum; j++){
        vector[i][j] = line+colum * value;
        }
    }
}

