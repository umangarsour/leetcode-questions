class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), dp(k);

        for (int x : nums) {
            vector<long long> ndp(k);

            int v = x % k;
            ndp[v]++;

            for (int r = 0; r < k; r++) {
                ndp[(r * v) % k] += dp[r];
            }

            dp = ndp;

            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};