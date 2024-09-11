#include <stdio.h>

#define N 5
#define W 10

int containerLoader(int weights[], int n) {
    int dp[W + 1] = {0};
    for (int i = 1; i <= W; i++)
        dp[i] = -1;

    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = weights[i]; j <= W; j++)
            if (dp[j - weights[i]] != -1)
                dp[j] = dp[j] > dp[j - weights[i]] + 1 ? dp[j] : dp[j - weights[i]] + 1;

    return dp[W];
}

int main() {
    int weights[N] = {1, 2, 3, 4, 5};
    int maxWeight = 10;
    int result = containerLoader(weights, N);
    if (result != -1)
        printf("Maximum number of items that can be loaded: %d\n", result);
    else
        printf("Cannot load items with given weights.\n");

    return 0;
}

