#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/*

salvar no /root como prog.c

-> compilar com " cc -o prog prog.c "

*/

int main(){
    
    int pid = fork();

    if(pid == 0){ /*processo filho */

            prinf("Filho");
            exit(0);
    }

   else if(pid > 0){
        
        int status, pidf;

        printf("Pai...");

        pidf= waitpid(pid, &status,  WIFEXITED(status));
    
    }

    return 0;
}
