#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

/* Example program for waitpid system call */
/* Author: Mario O. de Menezes - 2019 */

int main(void){
    pid_t childpid1, childpid2, pidw;
    int status;
    
    if(( childpid1 = fork()) == -1){
        perror("fork");
        exit(1);
    }
    if( childpid1 == 0){
        /* Child process; take a quick rest */
        printf("I'm the fast sleeper child %ld; I'll take a quick rest now ... \n", (long)getpid());
        usleep(500);
        printf("My rest is over; I'll exit now; FYI, my id is %ld: \n", (long)getpid());
        exit(0);
    }
    else{
        /* Parent process */
        printf("My first child is fast; it's pid is %ld\n", (long)childpid1);
        /* will fork another child; a longer sleeper */
        if ((childpid2 = fork()) == -1){
            pidw = wait(&status); /* if the first child is still running */
            printf("First child status %d\n", status);
            perror("fork 2 error, exiting...");
            exit(1);
        }
        if (childpid2 == 0){
            /* Child process; take a longer rest */
            printf("I'm one of the sleeper child %ld; I'll take a longer rest now ... sleeping\n", (long)getpid());
            sleep(3);
            exit(0);
        }
        /* Parent process waits for sleeper child */
        printf("I've a sleeper child %ld; have to wait for him...\n", (long)childpid2);
        pidw = waitpid(childpid2, &status, 0);
        if (pidw != childpid2) {
            perror ("waitpid error");
            exit(1);
        }
        printf("My sleeper child %ld awaked ...", (long)childpid2);
        printf("His termination status is: %d\n", status);
    }  
    return (0);
}
