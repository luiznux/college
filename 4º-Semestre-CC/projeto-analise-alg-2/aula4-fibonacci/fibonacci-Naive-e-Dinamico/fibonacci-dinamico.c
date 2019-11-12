# include <stdio.h>

// contadores para as duas funçoes, a ruim e a boa(dinamica)
// para ver a diferença de uso de funções 
long long int  contador_ruim = 0;

long long int contador_bom = 0;



//função fibonacci
long long int fibo(int n){

    contador_ruim++;

    if(n == 0) return 0;

    else if (n == 1) return 1;

    else return fibo(n-1) + fibo(n-2);

}



//fib dinamico que usa um vetor para armazenar resultados previos , afim de ganhar mais tempo
//recebo um n que é ate onde calculculo a função fibonacci
//e um vetor para armazenar os resutlados
long long int fib_dinamico( int n, long long int *vetor){

    contador_bom++;
    
    //caso seja chamado o fib de 0
    if(n == 0){
        vetor[0] = 0;
        return 0;
    }
    
    //caso seja chamado o fib de 1 e 2
    else if( n == 1 || n == 2){
        vetor[n] = 1;
        return 1;
    }
    
    //3 caso que nao tenho pre calculado o fibonacci, tenho que fazer a conta
    //porem ja possuo os valores anteriores guardados, evitando o recalculo
    //ai que esta a programação dinamica 
    //vou verificar se  n-1 ja foi calculado(igual a  -1)
    else if (vetor[n-1] == -1){

        vetor[n]  = fib_dinamico(n-1, vetor) + fib_dinamico(n-2, vetor);
    }
    return vetor[n];
}


// preenche um vetor de -1 
void preenche_saporra(long long int *vetor, int tamanho){
    
    for(int i =0; i < tamanho; i++){
        vetor[i] = -1;
    }

}



int main(){

    int coisa;

    printf("Digita ai Bazilao um numero para calcular o fibonacci, gloria a Tayrone! S2 \n");

    scanf("%d", &coisa);

    long long int  vetor_coisa[coisa];

    preenche_saporra(vetor_coisa, coisa); //preenche o vetor com -1

    printf("\n Fibo resulta em: %lld \n", fibo(coisa));

    printf("\n Contador ruim: %lld \n", contador_ruim);

    printf("\n Fibo rapidao : %lld \n",fib_dinamico(coisa, vetor_coisa));

    printf("\n Contador bom: %lld \n", contador_bom);

    fib_dinamico(coisa, vetor_coisa);

    return 0;
}

