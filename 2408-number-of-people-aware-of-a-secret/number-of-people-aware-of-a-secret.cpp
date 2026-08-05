class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        long long windowSum = 0;
        for (int i = 2; i <= n; i++) {
            if (i - delay >= 1) windowSum = (windowSum + dp[i - delay]) % MOD;
            if (i - forget >= 1) windowSum = (windowSum - dp[i - forget] + MOD) % MOD;
            dp[i] = windowSum;
        }
        long long ans = 0;
        for (int j = max(1, n - forget + 1); j <= n; j++) ans = (ans + dp[j]) % MOD;
        return (int)ans;
    }
};