#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t done = 0;

void handler(int sig) {
    done = 1;
}

int main() {

    sigset_t mask, oldmask, suspendmask;

    signal(SIGCHLD, handler);

    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);

    sigprocmask(SIG_BLOCK, &mask, &oldmask);

    pid_t pid = fork();

    if(pid == 0) {
        printf("Child: running...\n");
        sleep(2);
        printf("Child: exiting...\n");
        exit(0);
    }

    suspendmask = oldmask;
    sigdelset(&suspendmask, SIGCHLD);

    while(!done)
        sigsuspend(&suspendmask);

    sigprocmask(SIG_SETMASK, &oldmask, NULL);

    printf("Parent: Child finished.\n");

    return 0;
}