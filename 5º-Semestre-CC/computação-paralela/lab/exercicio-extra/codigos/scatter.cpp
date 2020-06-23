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

    // vetor para retorno das somas de cada processo
    int * soma = new int[atoi(argv[1])];

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

    // tamanho do chunk de cada processo
    int size_proc = MAXSIZE / nprocs;

    // vetor para acondicionar o chunk
    int * data_proc = new int[size_proc];

    // enviar os dados aos processos
    MPI_Scatter(data, size_proc, MPI_INT, data_proc, size_proc, MPI_INT, 0, MPI_COMM_WORLD);

    // cada processo faz a somatoria do seu chunk
    int soma_proc = 0;
    for (int i = 0; i < size_proc; i++){
        soma_proc += data_proc[i];
    }
    // cada processo imprime a sua soma
    printf("Proc. %d - soma = %d\n", nrank, soma_proc);

    // barreira para aguardar todos os processos
    MPI_Barrier(MPI_COMM_WORLD);

    // as somas sao enviadas ao processo 0
    MPI_Gather(&soma_proc, 1, MPI_INT, soma, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // rank 0 imprime o vetor que contem as somas de cada processo (inclusive a sua)
    if (nrank == 0){
    printf("-------   oi gente!!  -------\n");
        for (int i = 0; i < nprocs; i++){
            printf("proc %d - soma = %d\n", i, soma[i]);
        }
    }

    MPI_Finalize();

}
