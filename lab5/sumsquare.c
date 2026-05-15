#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int sum = 0;
    pid = fork();

    if(pid == 0)
    {
        for(int i=1;i<argc;i++)
        {
            int num = atoi(argv[i]);
            sum += num * num;
        }

        printf("Child: Sum of Squares = %d\n",sum);
        exit(sum);
    }
    else
    {
        int status;
        wait(&status);

        if(WIFEXITED(status))
        {
            printf("Parent received result = %d\n",WEXITSTATUS(status));
        }
    }

    return 0;
}