#include <stdio.h>
#include <stdlib.h>
#define TAM 1000

void preencheVetor(int *vet) {
  for(int i = 0; i <= TAM; i++) {
    vet[i] = -1;
  }
}

void imprimeVetor(int *vet) {
  for(int i = 0; i < TAM; i++) {
    printf("%d ", vet[i]);
  }
}

void geraPrecos(int *preco) {
  time_t t;
  srand((unsigned) time(&t));
  for(int i = 0; i < TAM; i++) {
    preco[i] = rand() % TAM+1;
  }
}

int hasteDina (int n, int *tabela, int *vet) {
  if (n == 0) return 0;

  if(vet[n] != -1) return vet[n];
  int max = -1;

  for (int i = 0; i < n; i++) {
    int temp = tabela[i] + hasteDina (n-i-1, tabela, vet);
    if (temp > vet[n]) {
      vet[n] = temp;
    }
  }
  return vet[n];
}

int haste (int n, int *tabela) {
  if (n == 0) return 0;

  int max = -1;

  for (int i = 0; i < n; i++) {
    int temp = tabela[i] + haste (n-i-1, tabela);
    if (temp > max) {
      max = temp;
    }
  }
  return max;
}

int main() {
  int vet[TAM+1];
  int tabela[TAM];
  geraPrecos(tabela);
  preencheVetor(vet);
  printf("Tabela: \n");
  imprimeVetor(tabela);
  printf("\nHaste Dinamico: %d", hasteDina(TAM, tabela, vet));
  return 0;
}
