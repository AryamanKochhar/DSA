#include <stdio.h>

// Recursive approach: Time complexity O(2^n)
// Computes maximum revenue by trying all possible cuts recursively
int rodCutRecursive(int price[], int n) {
    if (n == 0) return 0;
    int max_val = 0;
    for (int j = 1; j <= n; j++) {
        int temp = price[j - 1] + rodCutRecursive(price, n - j);
        if (temp > max_val) max_val = temp;
    }
    return max_val;
}

// Memoization approach: Time complexity O(n^2)
// Uses a memo array to store results of subproblems
int rodCutMemo(int price[], int n, int memo[]) {
    if (memo[n] != -1) return memo[n];
    int max_val = 0;
    for (int j = 1; j <= n; j++) {
        int temp = price[j - 1] + rodCutMemo(price, n - j, memo);
        if (temp > max_val) max_val = temp;
    }
    memo[n] = max_val;
    return max_val;
}

// Bottom-up DP: Time complexity O(2^n)
// Iteratively builds solution using a DP array
// Outer loop runs n times, inner loop runs up to i times, total O(n^2)
int rodCutBottomUp(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int max_val = 0;
        for (int j = 1; j <= i; j++) {
            if (max_val < price[j - 1] + dp[i - j]) {
                max_val = price[j - 1] + dp[i - j];
            }
        }
        dp[i] = max_val;
    }
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    int price[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    
    // Using bottom-up DP as per original request
    int result = rodCutBottomUp(price, n);
    printf("%d\n", result);
    
    // Optional: Uncomment to test recursive and memoized approaches
    /*
    int result_recursive = rodCutRecursive(price, n);
    printf("Recursive: %d\n", result_recursive);
    
    int memo[n + 1];
    for (int i = 0; i <= n; i++) memo[i] = -1;
    memo[0] = 0;
    int result_memo = rodCutMemo(price, n, memo);
    printf("Memoization: %d\n", result_memo);
    */
    
    return 0;
}