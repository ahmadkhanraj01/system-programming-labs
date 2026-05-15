#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    int n = argc - 1;

    int fds[n];
    int done[n];

    char buffer[100];
    fd_set readfds;

    // initialize
    for (int i = 0; i < n; i++)
    {
        fds[i] = open(argv[i + 1], O_RDONLY);
        done[i] = 0;
    }

    int remaining = n;

    while (remaining > 0)
    {
        FD_ZERO(&readfds);
        int maxfd = 0;

        for (int i = 0; i < n; i++)
        {
            if (!done[i])
            {
                FD_SET(fds[i], &readfds);
                if (fds[i] > maxfd)
                    maxfd = fds[i];
            }
        }

        select(maxfd + 1, &readfds, NULL, NULL, NULL);

        for (int i = 0; i < n; i++)
        {
            if (!done[i] && FD_ISSET(fds[i], &readfds))
            {
                int bytes = read(fds[i], buffer, sizeof(buffer));

                if (bytes > 0)
                {
                    write(1, buffer, bytes);
                }
                else
                {
                    done[i] = 1;
                    remaining--;
                    close(fds[i]);
                }
            }
        }
    }

    return 0;
}