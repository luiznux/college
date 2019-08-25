#include "funcionario.h"
#include <iostream>
using namespace std;

funcionario::funcionario(string nome, string cargo, float valor_hora,  int cpf){
    this->nome = nome;
    this->cargo = cargo;
    this->valor_hora = valor_hora;
    this->cpf = cpf;
}


funcionario::~funcionario(){
}


// para um mes
void funcionario::set_horas_de_trampo(int horas_trab, int mes){
    meses_do_ano[mes-1] = horas_trab;
}

void funcionario::calcula_salario(){
    //bruto
    cout << "Salario bruto: \n " << endl;
    for(int i =0; i < 12; i++){
        cout << "valor do mes " << i+1 << meses_do_ano[i] * valor_hora << endl;
    }

    //liquido
    cout << "Salario liquido: \n" << endl;
    for(int i=0; i<12; i++){
        cout << "Valor do mes: " << i+1 << meses_do_ano[i] * valor_hora * 0.1 << endl;
    }
}


