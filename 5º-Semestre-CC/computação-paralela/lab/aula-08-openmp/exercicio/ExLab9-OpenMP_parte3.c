/*
Nome: Luiz Tagliaferro Tia: 31861806

Exercício discutido via chamada online com:
Nome: Bruno Severo Camilo
Nome: Matheus Soares Santos
Nome: João Pedro Colafati Pedroso
Nome: Wanderson Bezerra Lima
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <stdbool.h>
#include <sys/time.h>
#define TAM 10
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

void forzada() {
  long somaTotal1 = 0;
  long somaTotal2 = 0;
  long somaTotal3 = 0;
  long somaTotal4 = 0;
  int numThreads = 4;
  int maiores = 0;
  int menores = 0;

  #pragma omp parallel 
  {
    #pragma omp single
    {
      #pragma omp task
      {
        for(int i = 0; i < TAM/2; i++) {
          for(int j = 0; j < TAM/2; j++) {
            somaTotal1 += matriz[i][j];
            if (matriz[i][j] > NUMERO){
              #pragma omp atomic
              maiores += 1;
            }
            if (matriz[i][j] < NUMERO){
              #pragma omp atomic
              menores += 1;
            }
          }
        }
      }

      #pragma omp task
      {
        for(int i = TAM/2; i < TAM; i++) {
          for(int j = 0; j < TAM/2; j++) {
            somaTotal2 += matriz[i][j];
            if (matriz[i][j] > NUMERO){
              #pragma omp atomic
              maiores += 1;
            }
            if (matriz[i][j] < NUMERO){
              #pragma omp atomic
              menores += 1;
            }
          }
        }
      }

      #pragma omp task
      {
        for(int i = 0; i < TAM/2; i++) {
          for(int j = TAM/2; j < TAM; j++) {
            somaTotal3 += matriz[i][j];
            if (matriz[i][j] > NUMERO){
              #pragma omp atomic
              maiores += 1;
            }
            if (matriz[i][j] < NUMERO){
              #pragma omp atomic
              menores += 1;
            }
          }
        }
      }

      #pragma omp task
      {
        for(int i = TAM/2; i < TAM; i++) {
          for(int j = TAM/2; j < TAM; j++) {
            somaTotal4 += matriz[i][j];
            if (matriz[i][j] > NUMERO){
              #pragma omp atomic
              maiores += 1;
            }
            if (matriz[i][j] < NUMERO){
              #pragma omp atomic
              menores += 1;
            }
          }
        }
      }
    }
  }
  printf("\n2. Paralelo For: ");
  printf("\nSoma total: %ld\n", somaTotal1 + somaTotal2 + somaTotal3 + somaTotal4);
  printf("Elementos maiores que 50: %d\n", maiores);
  printf("Elementos menores que 50: %d\n", menores);
}

void calcula_tempo(void (*f)(void), char *texto) {
  struct timeval start, end;
  gettimeofday(&start, NULL);
  (*f)();
  gettimeofday(&end, NULL);
  double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
  printf("Tempo %s: %.8f\n", texto, delta);
}

int main() {
  populaMatriz();
  imprimir();
  calcula_tempo(sequencial, "Sequencial");
  calcula_tempo(forzada, "For Paralelo");
}
