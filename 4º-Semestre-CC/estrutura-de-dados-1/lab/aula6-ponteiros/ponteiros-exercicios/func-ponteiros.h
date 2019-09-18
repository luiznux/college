#ifndef FUNC_PONTEIROS_H
#define FUNC_PONTEIROS_H
#include <iostream>


//função para ordenar o vetor
int minimum(int *a,int n, int k, int loc);
void selection(int *a,int n);

//funcoes do exercicio
void preeche_vetor_float(float *vetor, int tamanho);

void preeche_vetor_int(int *vetor, int tamanho);

void maximoMinimo(int *v, int N, int *maximo, int *minimo);

void troca(float *a, float *b);

float cria_vetores(int tamanho);

void printa_vetor_float(float *vetor, int tamanho);

void printa_vetor_int(int *vetor, int tamanho);

#endif
