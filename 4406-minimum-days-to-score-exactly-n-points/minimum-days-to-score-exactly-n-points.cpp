class Solution {
public:
    int minDays(int n) {
        const int INF = INT_MAX / 2;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        int maxK = 1;
        while((long long)(maxK+1) * (maxK+2) / 2 <= n) maxK++;

        for(int s = 1; s <= n; s++){
            for(int k = 1; k <= maxK; k++){
                long long t = (long long)k * (k + 1) / 2;
                if(t > s) break;
                if(dp[s - t] != INF){
                    dp[s] = min(dp[s], dp[s - (int)t] + k + 1);
                }
            }
        }

        return dp[n] - 1;
    }
};