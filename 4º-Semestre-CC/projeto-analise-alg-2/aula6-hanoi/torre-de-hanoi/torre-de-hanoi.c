#include <stdio.h>
/*
Algoritmo de Hanói

Não utilizamos programção dinamica visto que só é necessario fazer os movimento apenas uma vez para cada quantidade de discos, e os movimento são uma variação do movimento de 1 disco com a variação de movimentos com 2 discos.

Bruno Severo Camilo TIA; 41781619
Luiz  Tagliaferro   TIA; 31861806

*/


//contador dos movimentos dos discos
int movimentos;
//numero de discos
int discos;


/*
* Função que mostra os movimentos necessarios para montar a torre de hanoi
* n é o parametro para o numero de discos
*/
void torreHanoi (int n, char primeiraTorre, char segundaTorre, char terceiraTorre){

  movimentos ++;

   if (n==1) {
     //Caso base 1 peça move origem para destino
     printf("\n Disco 1 da torre %c para a torre %c", primeiraTorre, segundaTorre);
   return;
   }
    //Caso mais de 1 peça alterar o destino para auxiliar e depois alterar a origem para aux
    //Para fazer n é necessario fazer de n n-1 n-2 n-3 ... 1.
	  torreHanoi(n-1,primeiraTorre,terceiraTorre,segundaTorre);
	  printf("\n Disco %d da torre %c para a torre %c", n, primeiraTorre, segundaTorre);
	  torreHanoi(n-1,terceiraTorre,segundaTorre,primeiraTorre);
}


int main(){

   printf("Escolha a quantidade de discos -> ");
   scanf("%d",&discos);

   torreHanoi(discos,'A','B','C');
   printf("\n Total de %d movimentos \n", movimentos);

   return 0;
}
