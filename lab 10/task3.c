#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

void print_permissions(mode_t mode) {

    printf((S_ISDIR(mode)) ? "d" : "-");

    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");

    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");

    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

int main() {

    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;

    dir = opendir(".");

    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    printf("Directory Listing:\n\n");

    while ((entry = readdir(dir)) != NULL) {

        if (stat(entry->d_name, &fileStat) == -1) {
            perror("stat");
            continue;
        }

        print_permissions(fileStat.st_mode);

        printf(" %ld", fileStat.st_size);

        printf(" %s", ctime(&fileStat.st_mtime));

        printf(" %s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}