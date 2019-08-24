#include <iostream>

void quicksort(int valores[], int come�o, int fim)
{
	int i, j, pivo, aux;
	i = come�o;
	j = fim-1;
	pivo = valores[(come�o + fim) / 2];
	while(i <= j)
	{
		while(valores[i] < pivo && i < fim)
		{
			i++;
		}
		while(valores[j] > pivo && j > come�o)
		{
			j--;
		}
		if(i <= j)
		{
			aux = valores[i];
			valores[i] = values[j];
			valores[j] = aux;
			i++;
			j--;
		}
	}
	if(j > come�o)
		quicksort(valores, come�o, j+1);
	if(i < fim)
		quicksort(valores, i, fim);
}


