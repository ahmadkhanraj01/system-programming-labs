#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX 1000

char queue[MAX][1024];

int front = 0;
int rear = 0;

void enqueue(char *path) {

    strcpy(queue[rear++], path);
}

char* dequeue() {

    return queue[front++];
}

int isEmpty() {

    return front == rear;
}

void bfs(char *root) {

    enqueue(root);

    while (!isEmpty()) {

        char *current = dequeue();

        printf("%s\n", current);

        DIR *dir = opendir(current);

        if (!dir)
            continue;

        struct dirent *entry;

        while ((entry = readdir(dir)) != NULL) {

            if (strcmp(entry->d_name, ".") == 0 ||
                strcmp(entry->d_name, "..") == 0)
                continue;

            char path[1024];

            sprintf(path, "%s/%s", current, entry->d_name);

            struct stat st;

            if (stat(path, &st) == 0 &&
                S_ISDIR(st.st_mode)) {

                enqueue(path);
            }
        }

        closedir(dir);
    }
}

int main() {

    bfs(".");

    return 0;
}