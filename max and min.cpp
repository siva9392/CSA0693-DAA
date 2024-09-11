#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int min = arr[0], max = arr[0];

    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}

