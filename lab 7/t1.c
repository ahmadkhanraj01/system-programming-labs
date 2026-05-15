#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int source_fd, dest_fd;
    char buffer[100];
    int bytes_read;

    if (argc != 3)
    {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }

    source_fd = open(argv[1], O_RDONLY);
    if (source_fd < 0)
    {
        perror("Error opening source file");
        return 1;
    }

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0)
    {
        perror("Error opening destination file");
        close(source_fd);
        return 1;
    }

    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0)
    {
        write(dest_fd, buffer, bytes_read);
    }

    close(source_fd);
    close(dest_fd);

    printf("File copied successfully\n");

    return 0;
}