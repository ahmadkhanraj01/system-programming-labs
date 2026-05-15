#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
    if (argc < 2)
    {
        printf("Usafe: %s command1 command2 .....  commandN\n", argv[0]);
        return 1;
    }
    for(int i =1; i<argc; i++){
        pid_t pid = fork();
        if(pid == 0){
            //Child process
            char* args[] = {argv[i], NULL};
            execvp(args[0], args);
            perror("Exe failed.");
        }
    }
    //Parent waits for all children
    for(int i = 1; i<argc; i++){
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}