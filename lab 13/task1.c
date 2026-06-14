#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t child_finished = 0;

void handler(int sig) {
    printf("SIGCHLD received.\n");
    child_finished = 1;
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

    while(!child_finished);

    printf("Parent: Child finished.\n");

    return 0;
}