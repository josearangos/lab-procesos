#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (){
    int pid;
    int status;

    printf("Padre: %d\n", getpid());

    pid = fork();
    if (pid == 0){
        printf("Hijo %d\n", getpid());
        sleep(2);
        exit(EXIT_SUCCESS);
    }

    //Padre esperando el pid del proceso (child)
    waitpid(pid, &status, 0);


    if (WIFSIGNALED(status)){
        printf("Error\n");
    }
    else if (WEXITSTATUS(status)){
        printf("Exited Normally\n");
    }

    printf("Padre: %d\n", getpid());

    return 0;
}