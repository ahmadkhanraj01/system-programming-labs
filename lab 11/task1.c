#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void dfs(char *path, int level) {

    struct dirent *entry;

    DIR *dir = opendir(path);

    if (!dir)
        return;

    while ((entry = readdir(dir)) != NULL) {

        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        for (int i = 0; i < level; i++)
            printf("  ");

        printf("%s\n", entry->d_name);

        char newpath[1024];

        sprintf(newpath, "%s/%s", path, entry->d_name);

        struct stat st;

        if (stat(newpath, &st) == 0 &&
            S_ISDIR(st.st_mode)) {

            dfs(newpath, level + 1);
        }
    }

    closedir(dir);
}

int main() {

    dfs(".", 0);

    return 0;
}