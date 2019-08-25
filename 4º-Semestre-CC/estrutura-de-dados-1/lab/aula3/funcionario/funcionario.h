#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
using namespace std;


class funcionario{

private:

    string nome , cargo;

    int cpf, horas_trab, mes;

    float valor_hora;

    int meses_do_ano[12] = {0,0,0,0,0,0,0,0,0,0,0,0};


public:

    funcionario(string nome, string cargo, float valor_hora,  int cpf);
    ~funcionario();
    void set_horas_de_trampo(int horas_trab, int mes);
    void calcula_salario();

};

#endif


