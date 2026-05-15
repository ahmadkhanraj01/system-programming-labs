#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *src, *dest;
    char ch;

    if (argc < 3) {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "r");
    dest = fopen(argv[2], "w");

    if (!src || !dest) {
        printf("File error\n");
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}
