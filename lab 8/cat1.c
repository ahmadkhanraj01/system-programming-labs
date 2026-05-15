#include <unistd.h>

int main()
{
    char buf[100];
    int n;

    while ((n = read(0, buf, 100)) > 0)
        write(1, buf, n);

    return 0;
}
