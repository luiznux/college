#include "funcoes.h"

using namespace std;

int main(){


    //variaveis para armazenar os dados do vetor

    int tamanho_do_usuario;

    int *ponteiro_para_vetor;

    int maior_valor_vetor;

    float media_dos_valores;


    //entrada do usuario
    cout<<"Digite um valor inteiro para para o tamanho do vetor \n--> ";
    cin >> tamanho_do_usuario;

    //aloco o  vetor do usuario
    ponteiro_para_vetor = &aloca_vetor(tamanho_do_usuario);


    //preencho o vetor
    preeche_vetor(ponteiro_para_vetor, tamanho_do_usuario);

    //printo o vetor  para o usuario
    cout<<"\n";
    printa_vetor(ponteiro_para_vetor, tamanho_do_usuario);

    //armazeno o maior elemento do vetor
    maior_valor_vetor = maior_elemento(ponteiro_para_vetor, tamanho_do_usuario);

    //armazeno a media dos valores do vetor
    media_dos_valores = media_vetor(tamanho_do_usuario, ponteiro_para_vetor);
    //ordeno o vetor
    selection(ponteiro_para_vetor, tamanho_do_usuario);


    //print dos dados do vetor
    cout<<"\n    --> Os dados do seu vetor sao os seguintes: <--\n" << endl;

    cout<< "    * Maior elemento: " << maior_valor_vetor <<"\n" <<endl;

    cout<< "    * Media aritimetica dos valores: " << media_dos_valores << "\n" << endl;

    cout<< "    * Seu vetor ordenado: ";

    printa_vetor(ponteiro_para_vetor, tamanho_do_usuario);

    cout<< "\n \n";

    return 0;

}
