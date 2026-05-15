#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    if (rename(argv[1], argv[2]) != 0)
    {
        perror("Error moving/renaming file");
        return 1;
    }

    printf("File moved/renamed successfully.\n");
    return 0;
}