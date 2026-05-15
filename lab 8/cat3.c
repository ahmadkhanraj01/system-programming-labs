#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("file2.txt", O_RDONLY);

    char buf[100];
    int n;

    while ((n = read(fd, buf, 100)) > 0)
        write(1, buf, n);

    close(fd);
    return 0;
}
