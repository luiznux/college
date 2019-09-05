#ifndef FUNCOES_H
#define FUNCOES_H
#include <iostream>

int &aloca_vetor(int tamanho);

void preeche_vetor(int *vetor, int tamanho);

void printa_vetor(int *vetor, int tamanho);

float media_vetor(int tamanho,int *vetor);

int maior_elemento(int *vetor, int tamanho);

int minimum(int *a,int n, int k, int loc);

void selection(int *a,int n);

#endif
