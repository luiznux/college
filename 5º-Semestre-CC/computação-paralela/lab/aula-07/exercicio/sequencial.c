/*
Nome: Luiz Tagliaferro

Exercício discutido via chamada online com:
Nome: Bruno Severo Camilo
Nome: Edison Aguiar Neto
Nome: Matheus Soares Santos
Nome: João Pedro Colafati Pedroso
Nome: Wanderson Bezerra Lima

*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 4
#define MAX 100
#define MAIOR 50

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
  printf("Soma Total: %d\n", soma);
}

void maior(){
  int maior = 0;
  for(int i = 0; i < TAM; i++){
    for(int j = 0; j < TAM; j++){
      if (matriz[i][j] > MAIOR){
        maior += 1;
      }
    }
  }
    printf("\nElementos maiores que 50: %d\n", maior);
}

void menor(){
  int menor = 0;
  for(int i = 0; i < TAM; i++){
    for(int j = 0; j < TAM; j++){
      if (matriz[i][j] < MAIOR){
        menor += 1;
      }
    }
  }
    printf("\nElementos menores que 50: %d\n", menor);
}

int main(){
  populaMatriz();
  imprimir();
  soma();
  maior();
  menor();

  return 0;
}
