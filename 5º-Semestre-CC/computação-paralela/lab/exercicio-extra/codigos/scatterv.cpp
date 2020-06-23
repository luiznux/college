/*
---------------------------------------------------------------------------------
                     Executa a soma dos elementos de um vetor
---------------------------------------------------------------------------------
Este programa requer que seja especificado o numero de processos desejados
tanto no parametro -n como no argumento [1] da linha de comando.
exemplo: mpirun -n 4 ./exec 4
O primeiro argumento [0] do mpirun vem apos os parametros chave, sendo o algoritmo
a ser executado (./exec); a partir dai vem os demais argumentos [1], [2] ...
*/

#include "mpi/mpi.h"
#include <stdio.h>
#include <math.h>
#define MAXSIZE 20

int main(int argc, char **argv)
{
    // vetor central de dados
    int data[MAXSIZE] = {13,65,78,23,20,97,55,46,8,44,91,2,95,37,83,7,14,65,72,75};

    int  *chunk_size, *displs;

    // vetor para retorno das somas de cada processo
    int * soma = new int[atoi(argv[1])];

    int chunk[MAXSIZE];

    // inicializacao do ambiente MPI
    MPI_Init(&argc, &argv);
    int nprocs, nrank;
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &nrank);

	// verifica se a quantidade de elementos do vetor de dados da' divisao exata
	// pela quantidade de processos
    if (nrank == 0 && MAXSIZE % nprocs > 0) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (nrank == 0){

        chunk_size = new int[atoi(argv[1])];
        chunk_size[0] = 2;
        chunk_size[1] = 7;
        chunk_size[2] = 6;
        chunk_size[3] = 5;

        displs = new int[4];
        displs[0] = 0;
        displs[1] = 2;
        displs[2] = 9;
        displs[3] = 14;

    }

    for (int i = 0; i < MAXSIZE; i++){
        chunk[i] = 0;
    }

    // enviar os dados aos processos
    MPI_Scatterv(data, chunk_size, displs, MPI_INT, chunk, MAXSIZE, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < MAXSIZE; i++) {
        printf("P%dc%d=%d|", nrank, i, chunk[i]);
    }
    printf("\n");

    MPI_Finalize();

}



