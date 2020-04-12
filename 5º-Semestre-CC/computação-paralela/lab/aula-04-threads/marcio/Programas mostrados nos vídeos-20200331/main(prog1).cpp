
/*************************************************************************
     PROGRAMA PARA APRENDIZADO DE PTHREADS
     (prof. Marcio Feitosa)
     Cria 4 threads que alteram o valor de uma variavel do tipo int.
**************************************************************************/

#include <iostream>
#include <pthread.h>
#include <stdlib.h>

using namespace std;

//* x = variavel que sera' compartilhada
int x;

//*** param e' o struct de parametros para o metodo da thread
struct param
{
    //* essa estrutura foi inventada por mim
    int id; // identificador da thread; a main que vai especificar
    int valor; // valor que a thread vai atribuir a x
};
//+++

//* este e' um recurso de bloqueio
pthread_mutex_t bloqueio1;

void * alteraX(void * arg);

int main()
{
    cout << "Iniciando....." << endl;

    //* declaracao das threads
    pthread_t th1;
    pthread_t th2;
    pthread_t th3;
    pthread_t th4;

    //*******************************************************
    //      structs para envio de dados 'as threads
    // esses dados, na realidade, sao os parametros
    //
    param prm1;
    prm1.id = 1;
    prm1.valor = 11;

    param prm2;
    prm2.id = 2;
    prm2.valor = 22;

    param prm3;
    prm3.id = 3;
    prm3.valor = 33;

    param prm4;
    prm4.id = 4;
    prm4.valor = 44;
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    pthread_mutex_init(&bloqueio1, NULL);

    pthread_create(&th1,NULL,alteraX,(void *) &prm1);
    pthread_create(&th2,NULL,alteraX,(void *) &prm2);
    pthread_create(&th3,NULL,alteraX,(void *) &prm3);
    pthread_create(&th4,NULL,alteraX,(void *) &prm4);


    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    pthread_join(th4, NULL);


    cout << "\n\nNo fim, x ficou com valor " << x << endl;


    return 0;
}


void * alteraX(void * arg)
{

    pthread_mutex_lock(&bloqueio1);

    param * p  = (param *) arg;

    x = p->valor;

    cout << "\n\nThread " << p->id << " alterou x para " << x;

    pthread_mutex_unlock(&bloqueio1);


    return NULL;
}
