#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/errno.h>

#include <readline/readline.h>
#include <readline/history.h>


/* Example program for the mini-shell; 
 * - does tokenization of the command provided by the user for exec
 * - does timing execution of the command in the child process */
/* Author: Mario O. de Menezes - 2019 */



/* defined in the timeval_subtract.c file */
int timeval_subtract (struct timeval *, struct timeval *, struct timeval *);

int main(int argc, char *argv[]){
    pid_t childpid, pidw;
    struct timeval start_tv, end_tv, diff_tv;
    
    int status;
    int tmn;
    
    char *str1, *str2, *token, *subtoken;
    char *saveptr1, *saveptr2;
    int j,i;
    
    char *linha, *s, *prompt;
    char **cmd_argv;
    char *nome;
    cmd_argv =   calloc(256, sizeof(char*));
    for(i=0; i< 256; i++)
        cmd_argv[i] = calloc(2100, sizeof(char *));
    
    
    /* zeroing diff_tv timeval */
    diff_tv.tv_sec = 0;
    diff_tv.tv_usec = 0;
    
    tmn = strlen(argv[0]);
    tmn += 120 * sizeof(char *);  /* considering 120 digits for the execution time */
    
    nome = calloc(strlen(argv[0])+1, sizeof(char *));
    
    strcpy(nome, argv[0]);
    
    /* infinite loop; break it by issuing "0" at the prompt */
    for ( ; ; ) {
        prompt = calloc(tmn, sizeof(char *));
        snprintf(prompt, tmn, "%s (%ld.%04ld) #> ", nome, diff_tv.tv_sec, diff_tv.tv_usec/1000);
        linha = readline(prompt);
        
        /* printf("%s, length: %d, first char: %c\n", linha, (int)strlen(linha), linha[0]); */
        
        /* tokenization of command starts here */
        
        /* end of tokenization */
 
        free(prompt);
        
        if (strcmp(cmd_argv[0], "0") <= 0)
        {
            printf("Finishing mini-sh... bye\n");
            exit(0);
        }
        
        
        if(( childpid = fork()) == -1){
            perror("fork");
            exit(1);
        }

        /* time execution start */

        /* start of child execution
         * execvp called with cmd_argv properly built
         */        


        /* parent execution
         * wait for child
         * time execution end
         */
         
        /* freeing cmd_argv to avoid segfault */
        for(i=0;i<256;i++) 
            free((void *)cmd_argv[i]);
        free((void *) cmd_argv);
        /* allocating space for cmd_argv */
        cmd_argv =   calloc(256, sizeof(char*));
        for(i=0; i< 256; i++)
            cmd_argv[i] = calloc(2100, sizeof(char *));
        
    }
    return (0);
}
