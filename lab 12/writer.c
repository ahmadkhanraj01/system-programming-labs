#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {

    char *fifo = "myfifo";

    mkfifo(fifo, 0666);

    char msg[100];

    int fd = open(fifo, O_WRONLY);

    printf("Enter Message: ");
    fgets(msg, sizeof(msg), stdin);

    write(fd, msg, sizeof(msg));

    close(fd);

    return 0;
}