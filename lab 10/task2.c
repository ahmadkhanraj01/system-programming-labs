#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

int main() {

    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;

    dir = opendir(".");

    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    printf("File Information:\n\n");

    while ((entry = readdir(dir)) != NULL) {

        if (stat(entry->d_name, &fileStat) == -1) {
            perror("stat");
            continue;
        }

        printf("File Name: %s\n", entry->d_name);
        printf("File Size: %ld bytes\n", fileStat.st_size);
        printf("Last Modified: %s\n", ctime(&fileStat.st_mtime));
    }

    closedir(dir);

    return 0;
}