#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <unistd.h>



int   main()
{

    printf("NOMES: \n Luiz Fernando 31861806 \n Thiago Valença 31885731");
    int    ShmID;
    int    *ShmPTR;
    pid_t  pid;
    int    status;

    ShmID = shmget(IPC_PRIVATE, 4*sizeof(int), IPC_CREAT | 0666);
    // salvo nessa variavl o ponteiro para a regiao de mememoria compartilhada
    ShmPTR = (int *) shmat(ShmID, NULL, 0);
    ShmPTR[0] = 10;
    printf("Valor do pai %d \n",ShmPTR[0]);
    printf("Fiz o fork ...\n");
    pid = fork();
    if (pid < 0) { //verifico se o fork funcionou
        printf("*** ERRO FORK ***\n");
        exit(1);
    }else if (pid == 0) { //se funcionou vou chamar a função de filho e fazer as alterações
        ShmPTR[0] = ShmPTR[0] +5;
        printf("Mudei o valor durante o fork %d \n",ShmPTR[0]);
        exit(0);
    }
    printf("Apos o fork, o valor do pai é.. %d\n",ShmPTR[0]);
}

