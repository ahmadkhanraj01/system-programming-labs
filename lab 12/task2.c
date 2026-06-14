#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fildes[2];
    pipe(fildes);

    char msg[] = "Message from Parent";

    for(int i = 0; i < 3; i++) {
        if(fork() == 0) {

            close(fildes[1]);

            char buffer[100];
            read(fildes[0], buffer, sizeof(buffer));

            printf("Child %d received: %s\n", i + 1, buffer);

            close(fildes[0]);
            return 0;
        }
    }

    close(fildes[0]);

    write(fildes[1], msg, strlen(msg) + 1);

    close(fildes[1]);

    return 0;
}