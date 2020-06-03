/*

Nome: Luiz Tagliaferro   TIA: 31861806
Exercício discutido via chamada online com:
Nome: Bruno Severo Camilo
Nome: Matheus Soares Santos
Nome: Wanderson Bezerra Lima
Nome: João Pedro Colafati Pedroso
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define MAX 10

void populaMatriz(int **matriz) {
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      matriz[i][j] = rand() % MAX;
    }
  }
}

void imprimeMatriz(int **matriz){
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int **criaMatriz(int lin, int col) {
  int **m = malloc(sizeof(int*)*lin);
  for(int i = 0; i < lin; i++) {
    m[i] = malloc(sizeof(int)*col);
  }
  return m;
}

int somaMatriz(int** matriz) {
  int soma = 0;
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      soma += matriz[i][j];
    }
  }
  return soma;
}

int somaLinha(int** matriz, int lin) {
  int soma = 0;
  for(int i = 0; i < TAM; i++) {
    soma += matriz[lin][i];
  }
  return soma;
}

void bubbleSort(int *v) {
  for(int i = 0; i < TAM; i++) {
    for(int j = i; j < TAM; j++) {
      if(v[i] > v[j]) {
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }
}

int main(void) {
  
  clock_t inicioSeq, fimSeq;
  clock_t inicioPar, fimPar;

  int **m1 = criaMatriz(TAM, TAM);
  int **m2 = criaMatriz(TAM, TAM);
  int **m3 = criaMatriz(TAM, TAM);
  
  populaMatriz(m1);
  populaMatriz(m2);
  populaMatriz(m3);
  
  imprimeMatriz(m1);
  printf("\n");
  imprimeMatriz(m2);
  printf("\n");
  imprimeMatriz(m3);
  printf("\n\n");
  
  int somaGlobal = 0;
  inicioSeq = clock();
  somaGlobal += somaMatriz(m1);
  somaGlobal += somaMatriz(m2);
  somaGlobal += somaMatriz(m3);
  fimSeq = clock();
  
  printf("Soma Global = %d\n", somaGlobal);
  printf("Tempo Total Sequencial = %lfs\n", (double)(fimSeq-inicioSeq) /CLOCKS_PER_SEC);

  int vet1[TAM];
  int vet2[TAM];
  int vet3[TAM];
  int vetorFinal[TAM] = {};
  int resultado = 0;

/* Uma thread para cada matriz */
  inicioPar = clock();
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      for(int i = 0; i < TAM; i++) {
        vet1[i] = somaLinha(m1, i); 
      }
      bubbleSort(vet1);
    }

    #pragma omp section
    {
      for(int i = 0; i < TAM; i++) {
        vet2[i] = somaLinha(m2, i);
      }
      bubbleSort(vet2);
    }

    #pragma omp section
    {
      #pragma omp critical
      for(int i = 0; i < TAM; i++) {
        vet3[i] = somaLinha(m3, i);
      }
      bubbleSort(vet3);
    }
  }
  #pragma omp parallel for schedule(dynamic, 2)
  for(int i = 0; i < TAM; i++){
    vetorFinal[i] += vet1[i];
    vetorFinal[i] += vet2[i];
    vetorFinal[i] += vet3[i];
  }

  #pragma omp parallel for reduction(+:resultado)
  for(int i = 0; i < TAM; i++) {
    resultado += vetorFinal[i];
  }
  fimPar = clock();

  printf("\nSoma Threads: %d\n", resultado);
  printf("Tempo Total Paralelismo = %lfs\n", (double)(fimPar-inicioPar) /CLOCKS_PER_SEC);
  return 0;
}
