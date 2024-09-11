#include <stdio.h>
#include <limits.h>
#define MAX 100
void optimalBST(int keys[], int freq[], int n) {
    int cost[MAX][MAX], root[MAX][MAX];
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        root[i][i] = i;
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            int total_freq = 0;
            for (int k = i; k <= j; k++)
                total_freq += freq[k];

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r-1] : 0) + ((r < j) ? cost[r+1][j] : 0) + total_freq;
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }
    printf("Cost of Optimal BST: %d\n", cost[0][n-1]);
}
int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    optimalBST(keys, freq, n);
    return 0;
}

