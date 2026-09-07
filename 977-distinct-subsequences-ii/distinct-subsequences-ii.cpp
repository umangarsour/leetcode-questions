class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        // dp[i] = number of distinct subsequences (including empty) using s[0..i-1]
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // empty subsequence

        vector<int> lastSeen(26, -1); // last index (1-based dp index) where char last ended a subsequence

        for(int i = 1; i <= n; i++){
            char c = s[i-1];
            // "take" s[i-1]: appended to every subsequence counted in dp[i-1]
            // "notTake": subsequences already counted in dp[i-1]
            dp[i] = (2 * dp[i-1]) % MOD;

            // subtract subsequences double-counted due to a previous occurrence of the same char
            if(lastSeen[c - 'a'] != -1){
                dp[i] = (dp[i] - dp[lastSeen[c-'a'] - 1] + MOD) % MOD;
            }

            lastSeen[c - 'a'] = i;
        }

        // dp[n] includes the empty subsequence; subtract 1 for the final answer
        return (int)((dp[n] - 1 + MOD) % MOD);
    }
};