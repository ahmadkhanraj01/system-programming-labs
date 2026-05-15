#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid1,pid2;

    pid1 = fork();

    if(pid1 == 0)
    {
        char *env[] = {"MYVAR=HELLO",NULL};
        execle("/usr/bin/env","env",NULL,env);
        perror("execle failed");
        exit(1);
    }

    pid2 = fork();

    if(pid2 == 0)
    {
        execlp("ls","ls","-l",NULL);
        perror("execlp failed");
        exit(1);
    }

    wait(NULL);
    wait(NULL);

    printf("Both child processes finished\n");

    return 0;
}