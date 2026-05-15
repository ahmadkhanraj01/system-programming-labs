#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);

    fd_set readfds;
    char buffer[100];

    int done1 = 0, done2 = 0;

    while (!done1 || !done2)
    {
        FD_ZERO(&readfds);

        if (!done1) FD_SET(fd1, &readfds);
        if (!done2) FD_SET(fd2, &readfds);

        int maxfd = (fd1 > fd2 ? fd1 : fd2) + 1;

        select(maxfd, &readfds, NULL, NULL, NULL);

        if (!done1 && FD_ISSET(fd1, &readfds))
        {
            int n = read(fd1, buffer, sizeof(buffer));
            if (n > 0)
                write(1, buffer, n);
            else
                done1 = 1;
        }

        if (!done2 && FD_ISSET(fd2, &readfds))
        {
            int n = read(fd2, buffer, sizeof(buffer));
            if (n > 0)
                write(1, buffer, n);
            else
                done2 = 1;
        }
    }

    close(fd1);
    close(fd2);

    return 0;
}