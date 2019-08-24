#include <iostream>

void quicksort(int valores[], int começo, int fim)
{
	int i, j, pivo, aux;
	i = começo;
	j = fim-1;
	pivo = valores[(começo + fim) / 2];
	while(i <= j)
	{
		while(valores[i] < pivo && i < fim)
		{
			i++;
		}
		while(valores[j] > pivo && j > começo)
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
	if(j > começo)
		quicksort(valores, começo, j+1);
	if(i < fim)
		quicksort(valores, i, fim);
}


