#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>

/* Example program for timing the execution of a child process */
/* Author: Mario O. de Menezes - 2019 */


/* defined in the timeval_subtract.c file */
int timeval_subtract (struct timeval *, struct timeval *, struct timeval *);


int main(int argc, char *argv[]){
    pid_t childpid, pidw;
    struct timeval start_tv, end_tv, diff_tv;
    
    int status;
    
    if(( childpid = fork()) == -1){
        perror("fork");
        exit(1);
    }
    /* start of child execution */
    
    /* Aqui deve se iniciar a medicao do tempo de execucao do filho */
    
    if( childpid == 0){
        if (argc < 2) {
            /* printf("argv less than 2 args\n"); */
            exit(10);
        }
        
        /* Aqui deve ser colocado o codigo da chamada a system call
         * execvp; dois argumentos devem ser providos: o nome do programa
         * a ser executado e a lista (array) de argumentos 
         */
    }
    else{
        /* Parent process waits for sleeper child */
        pidw = wait(&status);
        
        /* quando o filho termina, nova chamada a gettimeofday para pegar
         * o final do tempo de execucao.
         * */
        
        
        if (pidw != childpid) {
            perror ("wait");
            exit(1);
        }
        
        /* faz a chamada a função timeval_subtract para pegar a diferenca
         * de tempo, que eh o tempo de execucao do filho.
         * depois imprime o resultado conforme formato indicado.
         */
        

    }  
    return (0);
}
