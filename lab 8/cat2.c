#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("file1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    char buf[100];
    int n;

    while ((n = read(0, buf, 100)) > 0)
    {
        if (buf[0] == 's')
            break;

        write(fd, buf, n);
    }

    close(fd);
    return 0;
}
