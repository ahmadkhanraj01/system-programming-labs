#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define SIZE 100
#define CHILDREN 10

int main() {

    int arr[SIZE];
    int pipefd[2];
    pipe(pipefd);

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 100;

    for (int i = 0; i < CHILDREN; i++) {

        pid_t pid = fork();

        if (pid == 0) {

            close(pipefd[0]);

            int start = i * 10;
            int sum = 0;

            for (int j = start; j < start + 10; j++)
                sum += arr[j];

            write(pipefd[1], &sum, sizeof(sum));
            close(pipefd[1]);
            exit(0);
        }
    }

    close(pipefd[1]);

    int total = 0, partial;

    for (int i = 0; i < CHILDREN; i++) {
        read(pipefd[0], &partial, sizeof(partial));
        total += partial;
    }

    close(pipefd[0]);

    for (int i = 0; i < CHILDREN; i++)
        wait(NULL);

    printf("Final Total Sum = %d\n", total);

    return 0;
}