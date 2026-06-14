#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {

    char *fifo = "myfifo";

    mkfifo(fifo, 0666);

    char buffer[100];

    int fd = open(fifo, O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Received Message: %s", buffer);

    close(fd);

    return 0;
}