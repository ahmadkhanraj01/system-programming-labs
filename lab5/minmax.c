#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid1,pid2;
    int status;

    pid1 = fork();

    if(pid1 == 0)
    {
        execv("./min", argv);
        perror("exec failed");
        exit(1);
    }

    pid2 = fork();

    if(pid2 == 0)
    {
        execv("./max", argv);
        perror("exec failed");
        exit(1);
    }

    wait(&status);
    wait(&status);

    printf("Min and Max calculation completed\n");

    return 0;
}