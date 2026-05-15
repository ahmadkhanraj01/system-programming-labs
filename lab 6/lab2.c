#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;
    char message[100];

    pipe(fd);

    pid = fork();

    if (pid == 0) {
        // Child process
        close(fd[1]); // Close write end

        read(fd[0], message, sizeof(message));
        printf("Child Process Received Message: %s\n", message);
        printf("Child PID: %d\n", getpid());
        printf("Child is running a long process (sleep for 30 seconds)...\n");

        sleep(30);

        printf("Child process finished.\n");
        close(fd[0]);
    }
    else {
        // Parent process
        close(fd[0]); // Close read end

        char parentMsg[] = "Hello from Parent through Pipe!";
        write(fd[1], parentMsg, strlen(parentMsg) + 1);

        printf("Parent Process PID: %d\n", getpid());
        printf("Message sent to child.\n");
        printf("Use kill command from terminal if needed.\n");

        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
