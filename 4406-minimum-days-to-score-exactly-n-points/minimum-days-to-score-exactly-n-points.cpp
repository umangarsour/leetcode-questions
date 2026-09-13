class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int d = 1, j = 1; j <= i; j += ++d) {
                dp[i] = min(dp[i], dp[i - j] + d + (i != j));
            }
        }
        return dp[n];
    }
};