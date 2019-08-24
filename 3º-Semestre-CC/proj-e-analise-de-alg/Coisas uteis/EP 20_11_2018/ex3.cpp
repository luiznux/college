// Luiz Henrique Monteiro de Carvalho - 41719468
// Patrick Gandolf Gioz - 41700627

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char list[251];
	int x, y, a, b, c, counter1, counter2, num, num2;
	printf("Digite uma sequencia com 250 caracteres: ");
	scanf("%s", list); 
	num = strlen(list);
	printf("\n");

	for (x=0; i<num; x++){//varre a lista comparando com a variavel x
		y=x; //j será o variavel de comparação com x
		counter1 = 0; //contador de repetições
		
		
		if (list[x] == list[y+1]){//contagem de letras que aparecem sozinhas, se a variavel i for igual a proxima
			while (lista[x] == list[y]){
				counter1++; //se for igual soma no contador
				y++; //passa para o proximo item para comparar com o i				
			}
			
			x = x + counter1 - 1; //pular os itens repetidos da lista
		  
			//printa o caractere + numero de repetições
			if (x<(num-1)){
				printf("%c%d - ", list[x], counter1);
			}else{
				printf("%c%d\n", list[x], counter1);
			}

		
		}else{//contagem de subsequencias - se a variavel for diferente da proxima
			a=0; //determina a posição dos itens adicionados para formar a subsequencia
			c=0; //auxilia na comparação da subsequencia com os outros caracteres da lista
			counter2 = 0; //contador de letras iguais ao comparar uma subsequencia com uma possivel subsequencia
			char subsequencia[251] = "";  
			
			do{//formata a subsequencia
				if(y+1 > num){ //se o proximo item estiver em uma posição maior que o tamanho da lista
					break;
				}
				subsequencia[a]=list[y];//Adiciona o item na posição y da Lista na subsquencia na posição a
				a++;//passa para a proxima posição da subsequencia
				y++;//passa para o proximo item para comparar com o i	
			}while((list[x] != list[y]) && (list[y] != list[y+1])); //repeti x enquanto for diferente de y e enquanto y for diferente do caractere seguinte
			
			quant2 = strlen(subsequencia); //grava a quantidade de caracteres da subsequencia
			
			for (b=x; b<num; b++){//varre a lista comparando a subsequencia com um caractere b
				if (counter2 < num2){ //se a quantidade do counter2 for menor que a quantidade de caracteres na lista
					if ((subsequencia[c] == list[b]) && y<num){
						counter2++; //somar 1 no counter2
						c++; //passa para a proxima letra da subsequencia
					}else{
						b = num; 
					}
				}
				if (counter2 == num2){ //quando a quantidade do counter2 for igual que a quantidade de caracteres na lista
				  counter1++; //somar 1 no counter1
				  counter2 = 0; //counter2 zerado
				  c=0;//volta para o inicio da subsequencia
				}
			}
			
			x = x + (num2*counter1) - 1; //pula os itens repetidos da subsequencia
			
			//printa a subsequencia + quantidade da repetição
			if (i<(num-1)){
				printf("%s%d - ",subsequencia, counter1);
			}else{
				printf("%s%d",subsequencia, counter1);
			}
			
		}
	}
	return 0;
}
