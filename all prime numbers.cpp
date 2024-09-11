#include <stdio.h>
int main() {
    int n;
    printf("Enter the upper limit: ");
    scanf("%d", &n);
    int isPrime[n + 1];
    for (int i = 0; i <= n; i++) isPrime[i] = 1;
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) isPrime[i] = 0;
        }
    }
    printf("Prime numbers up to %d:\n", n);
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) printf("%d ", p);
    }
    printf("\n");
    return 0;
}

