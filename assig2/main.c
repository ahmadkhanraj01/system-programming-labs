#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        execl("./copy", "copy", "source.txt", "dest.txt", NULL);
        printf("Exec failed\n");
    }
    else {
        wait(NULL);
        printf("File copy completed by child process\n");
    }

    return 0;
}
