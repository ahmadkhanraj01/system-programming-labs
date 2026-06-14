#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fildes[2];
    pipe(fildes);

    pid_t pid = fork();

    if(pid == 0) {
        // Child Process
        close(fildes[0]);

        char msg[] = "Hello from Child";
        write(fildes[1], msg, strlen(msg) + 1);

        close(fildes[1]);
    }
    else {
        // Parent Process
        close(fildes[1]);

        char buffer[100];
        read(fildes[0], buffer, sizeof(buffer));

        printf("Parent received: %s\n", buffer);

        close(fildes[0]);
    }

    return 0;
}