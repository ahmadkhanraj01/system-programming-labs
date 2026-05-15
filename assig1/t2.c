#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigint(int sig) {
    printf("\nSIGINT received (Ctrl+C pressed).\n");
    printf("Exiting the program...\n");
    exit(0);
}

int main() {

    // Register SIGINT handler
    signal(SIGINT, handle_sigint);

    printf("Program is running. Press Ctrl+C to stop.\n");

    while (1) {
        printf("Working...\n");
        sleep(2);
    }

    return 0;
}