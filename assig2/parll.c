#include <stdio.h>
#include <pthread.h>

int arr[5] = {10, 20, 5, 40, 15};

int sum1 = 0, sum2 = 0;
int max1, max2;

void* part1(void* arg) {
    max1 = arr[0];

    for (int i = 0; i < 2; i++) {
        sum1 = sum1 + arr[i];

        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }

    return NULL;
}

void* part2(void* arg) {
    max2 = arr[2];

    for (int i = 2; i < 5; i++) {
        sum2 = sum2 + arr[i];

        if (arr[i] > max2) {
            max2 = arr[i];
        }
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, part1, NULL);
    pthread_create(&t2, NULL, part2, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    int total_sum = sum1 + sum2;

    int max;
    if (max1 > max2)
        max = max1;
    else
        max = max2;

    float avg = (float)total_sum / 5;

    printf("Sum = %d\n", total_sum);
    printf("Average = %.2f\n", avg);
    printf("Max = %d\n", max);

    return 0;
}