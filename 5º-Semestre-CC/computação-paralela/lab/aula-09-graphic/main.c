#include "mpi/mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM 50

void populaVetor(int *v) {
  for(int i = 0; i < TAM; i++) {
    v[i] = rand() % TAM;
  }
}

void imprimeVetor(int *v){
  printf("[ ");
  for(int i = 0; i < TAM; i++){
    printf("%d ", v[i]);
  } 
  printf("]\n");
}

int main(int argc, char **argv){
    int id, numprocs;
    int data[TAM], i, x, min, max, valor=0, maior;
    populaVetor(data);
      imprimeVetor(data);

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    MPI_Bcast(data, TAM, MPI_INT, 0, MPI_COMM_WORLD);
    x = TAM/numprocs;
    min = id * x;
    max = min + x;
    for(i = min; i < max; i++){
        if(data[i] > valor)
      valor = data[i];
    }
    printf("Rank %d pegou %d\n", id, valor);

    MPI_Reduce(&valor, &maior, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if(0 == id) {
        printf("O maior é %d.\n", maior);
    }

    MPI_Finalize();
}
