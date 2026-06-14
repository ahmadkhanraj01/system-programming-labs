#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {

    char *fifo1 = "fifo1";
    char *fifo2 = "fifo2";

    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    char msg[100], buffer[100];

    while(1) {

        int fdr = open(fifo1, O_RDONLY);

        read(fdr, buffer, sizeof(buffer));

        printf("Friend: %s", buffer);

        close(fdr);

        int fdw = open(fifo2, O_WRONLY);

        printf("You: ");
        fgets(msg, sizeof(msg), stdin);

        write(fdw, msg, strlen(msg)+1);

        close(fdw);
    }

    return 0;
}