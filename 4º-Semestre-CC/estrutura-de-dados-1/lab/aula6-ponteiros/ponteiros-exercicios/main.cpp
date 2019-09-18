#include "func-ponteiros.h"

using namespace std;

int main(){

    //teste da questao 1
    int tamanho_vet_int = 4;
    int vetor_de_inteiros[tamanho_vet_int];

    cout << "Vamos preencher seu vetor: \n";
    preeche_vetor_int(vetor_de_inteiros, tamanho_vet_int);

    int maior, menor;
    maximoMinimo(vetor_de_inteiros, tamanho_vet_int, &maior, &menor);

    cout << endl;
    cout << "O maior elemento é: "<< maior << endl << "\n";
    cout <<"E o menor é: " << menor << endl << "\n";

    cout <<"=======================================";

    return 0;
}
