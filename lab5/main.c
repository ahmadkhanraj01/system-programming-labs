#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
    if (argc < 3)
    {
        printf("Usafe: %s command1 command2 .....  commandN\n", argv[0]);
        return 1;
    }
    pid_t pid1, pid2;
    pid1 = fork();
    if(pid1 == 0){
        execv("./add", argv);
        perror("Exec add failed. ");
        exit(1);
    }
    pid2 = fork();
    if(pid2 == 0){
        execv("./mul", argv);
        perror("Exec mul failed. ");
        exit(1);
    }
    wait(NULL);
    wait(NULL);

    printf("Both processes completed. \n");

    return 0;
}