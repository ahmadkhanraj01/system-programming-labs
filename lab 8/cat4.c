#include <unistd.h>
#include <fcntl.h>

int main()
{
    int src = open("f1.txt", O_RDONLY);
    int dest = open("f2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    char buf[100];
    int n;

    while ((n = read(src, buf, 100)) > 0)
        write(dest, buf, n);

    close(src);
    close(dest);
    return 0;
}
