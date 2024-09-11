#include <stdio.h>
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int left = 0, right = n - 1;
    int temp[n];
    for (int size = 1; size <= right; size = 2 * size) {
        for (int l = 0; l < right; l += 2 * size) {
            int mid = l + size - 1;
            int r = (l + 2 * size - 1) < right ? (l + 2 * size - 1) : right;
            int i = l, j = mid + 1, k = l;
            while (i <= mid && j <= r) {
                if (arr[i] <= arr[j]) {
                    temp[k] = arr[i];
                    i++;
                } else {
                    temp[k] = arr[j];
                    j++;
                }
                k++;
        }
            while (i <= mid) {
                temp[k] = arr[i];
                i++;
                k++;
            }
            while (j <= r) {
                temp[k] = arr[j];
                j++;
                k++;
            }
            for (int i = l; i <= r; i++) {
                arr[i] = temp[i];
            }
        }
    }
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

