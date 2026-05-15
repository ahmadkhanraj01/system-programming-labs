#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int numbers[6];
    int sum1 = 0, sum2 = 0;
    pid_t pid1, pid2;

    // First child for input
    pid1 = fork();

    if (pid1 == 0) {
        printf("INPUT PROCESS:\n");
        printf("Enter 6 numbers:\n");
        for (int i = 0; i < 6; i++) {
            scanf("%d", &numbers[i]);
        }

        printf("Numbers entered: ");
        for (int i = 0; i < 6; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");

        return 0;
    }
    else {
        wait(NULL);  
        printf("\nPROCESSING PROCESS:\n");
        numbers[0] = 10;
        numbers[1] = 20;
        numbers[2] = 30;
        numbers[3] = 40;
        numbers[4] = 50;
        numbers[5] = 60;

        pid2 = fork();

        if (pid2 == 0) {
            for (int i = 0; i < 3; i++) {
                sum1 += numbers[i];
            }
            for (int i = 3; i < 6; i++) {
                sum2 += numbers[i];
            }

            printf("First half sum = %d\n", sum1);
            printf("Second half sum = %d\n", sum2);
            printf("Total sum = %d\n", sum1 + sum2);

            return 0;
        }
        else {
            wait(NULL);
            printf("\nOUTPUT PROCESS:\n");
            printf("Final result displayed successfully.\n");
        }
    }

    return 0;
}
