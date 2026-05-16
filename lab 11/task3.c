#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void pfind(char *path, char *filename) {

    DIR *dir = opendir(path);

    if (!dir)
        return;

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {

        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        char fullpath[1024];

        sprintf(fullpath, "%s/%s", path, entry->d_name);

        if (strcmp(entry->d_name, filename) == 0) {

            printf("Found: %s\n", fullpath);
        }

        struct stat st;

        if (stat(fullpath, &st) == 0 &&
            S_ISDIR(st.st_mode)) {

            pfind(fullpath, filename);
        }
    }

    closedir(dir);
}

int main() {

    char filename[100];

    printf("Enter file name to search: ");

    scanf("%s", filename);

    pfind(".", filename);

    return 0;
}