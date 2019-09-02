#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

/* Example program for wait system call */
/* Author: Mario O. de Menezes - 2019 */

int main(void){
    pid_t childpid, pidw;
    int status;
    
    if(( childpid = fork()) == -1){
        perror("fork");
        exit(1);
    }
    if( childpid == 0){
        /* Child process; take a rest sleeping */
        printf("I'm a sleeper child %ld; I'll take a rest now ... sleeping\n", (long)getpid());
        sleep(2);
        exit(0);
    }
    else{
        /* Parent process waits for sleeper child */
        printf("I've a sleeper child %ld; have to wait for him...\n", (long)childpid);
        pidw = wait(&status);
        if (pidw != childpid) {
            perror ("wait");
            exit(1);
        }
        printf("My sleeper child awaked ...");
        printf("His termination status is: %d\n", status);
    }  
    return (0);
}
