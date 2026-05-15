#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
long factorial(int n)
{
    if (n <= 1)
        return 1;
    long fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <num1> <num2> ...\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            int num = atoi(argv[i]);
            long result = factorial(num);

            printf("Number=%d | PID=%d | Factorial=%ld\n",
                   num, getpid(), result);

            exit(0);
        }
    }
    for (int i = 1; i < argc; i++)
        wait(NULL);

    return 0;
}