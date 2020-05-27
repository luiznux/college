/*
Nome: Luiz Tagliaferro TIA: 3186180-6

Exercício discutido via chamada online com:
Nome: Bruno Severo Camilo
Nome: Edison Aguiar Neto
Nome: Matheus Soares Santos
Nome: João Pedro Colafati Pedroso
Nome: Wanderson Bezerra Lima
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <stdbool.h>
#include <time.h>
#define TAM 4
#define MAX 100
#define NUMERO 50

int matriz[TAM][TAM];

void populaMatriz() {
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      matriz[i][j] = rand() % MAX;
    }
  }
}

void imprimir(){
  for(int i = 0; i < TAM; i++){
    for(int j = 0; j < TAM; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void soma(){
  int soma;
  for(int i = 0; i < TAM; i++){
    for(int j = 0; j < TAM; j++){
      soma += matriz[i][j];
    }
  }
  printf("\nSoma Total: %d\n", soma);
}

void maior(){
  int maior = 0;
  for(int i = 0; i < TAM; i++){
    for(int j = 0; j < TAM; j++){
      if (matriz[i][j] > NUMERO){
        maior += 1;
      }
    }
  }
    printf("Elementos maiores que 50: %d\n", maior);
}

void menor() {
  int menor = 0;
  for(int i = 0; i < TAM; i++){
    for(int j = 0; j < TAM; j++){
      if (matriz[i][j] < NUMERO){
        menor += 1;
      }
    }
  }
    printf("Elementos menores que 50: %d\n", menor);
}

void sequencial() {
  printf("1. Sequencial:");
  soma();
  maior();
  menor();
}


/*-------------------- FOR ---------------------------*/
void paraleloFor(int i, long *somaTotal, int *maiores, int *menores) {
  for(int j = 0; j < TAM; j++) {
    #pragma omp atomic //locka a variavel para nao gerar inconsistência
    *somaTotal += matriz[i][j];
    if (matriz[i][j] > NUMERO){
      #pragma omp atomic
      *maiores += 1;
    }
    if (matriz[i][j] < NUMERO){
      #pragma omp atomic
      *menores += 1;
    }
  }
}

/*
Paralelizamos cara quadrante da matriz em uma thread.
4 threads no total, realizando cada operaçao(soma, maior e menor), em cada thread.
*/
void forzada() {
  long somaTotal = 0;
  int numThreads = 4;
  int maiores = 0;
  int menores = 0;

  #pragma omp parallel for
  for(int i = 0; i < TAM; i++) {

    if(i%numThreads == 0)
      paraleloFor(i, &somaTotal, &maiores, &menores);

    else if(i%numThreads == 1)
      paraleloFor(i, &somaTotal, &maiores, &menores);

    else if(i%numThreads == 2)
      paraleloFor(i, &somaTotal, &maiores, &menores);

    else
      paraleloFor(i, &somaTotal, &maiores, &menores);
  }
  printf("\n2. Paralelo For: ");
  printf("\nSoma total: %ld\n", somaTotal);
  printf("Elementos maiores que 50: %d\n", maiores);
  printf("Elementos menores que 50: %d\n", menores);
}

/* ----------------WHILE------------------------------ */
void paraleloWhile() {
  bool fim = false;
  int linha = 0;
  long somaTotal = 0;
  int numThreads = 4;
  int maiores = 0;
  int menores = 0;

  // omp_lock_t bloq;
  // omp_init_lock(&bloq);

  #pragma omp parallel private (fim)
  {
    while(linha < TAM){
      if(linha%numThreads == 0) {
        int coluna = 0;
        while(coluna < TAM) {
          #pragma omp atomic
          somaTotal += matriz[linha][coluna];

          if (matriz[linha][coluna] > NUMERO){
            #pragma omp atomic
            maiores += 1;
          }
          if (matriz[linha][coluna] < NUMERO){
            #pragma omp atomic
            menores += 1;
          }

          coluna++;
        }

      } else if(linha%numThreads == 1) {
        int coluna = 0;
        while(coluna < TAM) {
          #pragma omp atomic
          somaTotal += matriz[linha][coluna];

          if (matriz[linha][coluna] > NUMERO){
            #pragma omp atomic
            maiores += 1;
          }
          if (matriz[linha][coluna] < NUMERO){
            #pragma omp atomic
            menores += 1;
          }
          coluna++;
        }

      } else if(linha%numThreads == 2) {
        int coluna = 0;
        while(coluna < TAM) {
          #pragma omp atomic
          somaTotal += matriz[linha][coluna];

          if (matriz[linha][coluna] > NUMERO){
            #pragma omp atomic
            maiores += 1;
          }
          if (matriz[linha][coluna] < NUMERO){
            #pragma omp atomic
            menores += 1;
          }
          coluna++;
        }

      } else {
        int coluna = 0;
        while(coluna < TAM) {
          #pragma omp atomic
          somaTotal += matriz[linha][coluna];

          if (matriz[linha][coluna] > NUMERO){
            #pragma omp atomic
            maiores += 1;
          }
          if (matriz[linha][coluna] < NUMERO){
            #pragma omp atomic
            menores += 1;
          }
          coluna++;
        }
      }
      #pragma omp atomic
      linha++;
    }
  }
  printf("\n3. Paralelo While: ");
  printf("\nSoma total: %ld\n", somaTotal);
  printf("Elementos maiores que 50: %d\n", maiores);
  printf("Elementos menores que 50: %d\n", menores);
}


void calcula_tempo(void (*f)(void), char *texto) {
  clock_t inicio = clock();
  (*f)();
  clock_t fim = clock();
  printf("Tempo %s: %.8f\n", texto, (fim-inicio)/ (double)CLOCKS_PER_SEC);
}

int main(){

  populaMatriz();
  imprimir();
  calcula_tempo(sequencial, "Sequencial");
  calcula_tempo(forzada, "For Paralelo");
  calcula_tempo(paraleloWhile, "While Paralelo");
}
