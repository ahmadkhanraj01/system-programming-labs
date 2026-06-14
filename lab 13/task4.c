#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main() {

    sigset_t set;
    int sig;

    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);

    sigprocmask(SIG_BLOCK, &set, NULL);

    pid_t pid = fork();

    if(pid == 0) {
        printf("Child: running...\n");
        sleep(2);
        printf("Child: exiting...\n");
        exit(0);
    }

    sigwait(&set, &sig);

    printf("Parent: SIGCHLD received (%d)\n", sig);

    return 0;
}