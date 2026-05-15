#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 5, 40, 15};
    int n = 5;

    int sum = 0;
    int max = arr[0];

    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];

        if (arr[i] > max) {
            max = arr[i];
        }
    }

    float avg = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);
    printf("Max = %d\n", max);

    return 0;
}
