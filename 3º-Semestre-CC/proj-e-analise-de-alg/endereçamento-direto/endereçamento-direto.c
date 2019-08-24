#include <stdio.h>

// imprime
void imprimir(int *vetor , int tam){
    
    printf("\n[");
    for(int i =0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
    printf("] \n");
}
// verifica o numero de vezes que cada elemento aparece em um um vetor
// e armazena elas em um vetor auxiliar 
void ocorrencias(int *vetor,int *vetor_chave,int tam){ 
    //primeiro laço que varre o vetor de entrada e adiciona ao vetor das chaves
    for(int i = 0; i < tam; i++){
        vetor_chave[vetor[i]]++;
    }

}
///preencho com zeros um vetor
void preenche_zeros(int *vetor){
    //vetor com as chaves de cada valor
    for(int i=0; i < 100; i++){
        vetor[i] = 0;
    }
}

//ordena um vetor usando como parametros um vetor chave com o numero de ocorrencias de
// de cada elemento do vetor que vai ser ordenado 
void ordena(int *vetor,int tam,int *vetor_chave )
{ 
    //segundo laço para substituir os elementos do vetor de entrada
    int cont_entrada = 0; // contador do vetor de entrada
    for (int cont_chave = 0; cont_chave < 100; cont_chave++){
        if (cont_entrada == tam) { // se passar de 20, ja preechi o vetor todo
                break;
        } else {
            // se tiver ocorrencia do valor no vetor_chave eu adiciono ele no vetor_entrada
            if(vetor_chave[cont_chave] > 0){

                // adiciona o elemento na posição do vetor original
                vetor[cont_entrada] = cont_chave;

                // ando no indice do vetor original
                cont_entrada++;

                // decremento o elemento do vetor chave pois ele ja foi adicionado
                // exemplo se tem 2, na posição 3, agora tem 1 pois a ocorrencia
                // ja foi registrada
                vetor_chave[cont_chave]--;

                // faço ele continuar na posição do vetor chave ate ficar zero,
                // ou seja , zerar as ocorrencias do numero
                cont_chave --;   
            }
        }
        
    }
}

//chama todas as funções
void sort_enderecamento(int *vetor,int tam){

    int vetor_chave[100];
    preenche_zeros(vetor_chave);
    ocorrencias(vetor, vetor_chave,tam);
    ordena(vetor,tam,vetor_chave);
    imprimir(vetor,tam);
}




int main()
{
    //vetor de entrada
    int vetor_entrada[20] = {5,6,7,4,9,1,2,3,9,0,22,12,3,2,99,16,8,6,0,19};
    int tam = sizeof(vetor_entrada)/sizeof(vetor_entrada[0]);

    sort_enderecamento(vetor_entrada, tam);
 
    return 0;
}
