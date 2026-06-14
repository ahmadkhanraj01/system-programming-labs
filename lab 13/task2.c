#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("SIGCHLD received.\n");
}

int main() {

    signal(SIGCHLD, handler);

    pid_t pid = fork();

    if(pid == 0) {
        printf("Child: running...\n");
        sleep(2);
        printf("Child: exiting...\n");
        exit(0);
    }

    pause();

    printf("Parent: resumed after pause.\n");

    return 0;
}