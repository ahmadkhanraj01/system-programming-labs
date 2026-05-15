#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    if (unlink(argv[1]) == -1)
    {
        perror("Error deleting file");
        return 1;
    }

    printf("File deleted successfully.\n");
    return 0;
}
