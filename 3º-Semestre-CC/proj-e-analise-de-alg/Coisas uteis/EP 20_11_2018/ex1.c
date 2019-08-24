// Luiz Henrique Monteiro de Carvalho - 41719468
// Patrick Gandolf Gioz - 41700627

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char array[251];
	int a, b, counter, quant;

	printf("Digite a sequencia: ");
	scanf("%s", array); //ler array
	quant = strlen(array); //conta e guarda a quantidade de caracteres
	printf("\n");
	
	for (a=0; a<quant; a++){ //loop for comparando com um caractere "a"
		b=a; //"b" vai compara com a 
		counter = 0; //conta caracteres repetidos
		
		//contagem de letras isoladas
		while (array[a] == array[b]){
			counter++;//sendo igual soma no contador
			b++;//passa para o proximo item para comparar com o "a"				
		}
		
		a = a + counter - 1; //pula os itens repetidos do array
		
		//printa caractere e suas repeticoes
		if (a<(quant-1)){
			printf("%c%d - ", array[a], counter); 
		}else{
			printf("%c%d\n", array[a], counter);
		} 		
	}
	return 0;
}
