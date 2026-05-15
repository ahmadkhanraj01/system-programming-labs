#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void copy_file(const char *src, const char *dest)
{
    int in = open(src, O_RDONLY);
    int out = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    char buffer[1024];
    int n;

    while ((n = read(in, buffer, sizeof(buffer))) > 0)
    {
        write(out, buffer, n);
    }

    close(in);
    close(out);
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage: %s src1 dest1 src2 dest2\n", argv[0]);
        return 1;
    }

    copy_file(argv[1], argv[2]); // first file
    copy_file(argv[3], argv[4]); // second file

    printf("Sequential copy completed\n");

    return 0;
}