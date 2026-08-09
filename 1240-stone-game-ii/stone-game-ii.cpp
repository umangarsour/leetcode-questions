class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suf(n+1, 0);
        for(int i=n-1;i>=0;i--) suf[i] = suf[i+1] + piles[i];

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1;i>=0;i--){
            for(int m=1;m<=n;m++){
                int best = 0;
                for(int x=1;x<=2*m && i+x<=n;x++){
                    int nextM = max(m, x);
                    int opp = (i+x <= n) ? dp[i+x][nextM] : 0;
                    int cur = suf[i] - suf[i+x] + (suf[i+x] - opp);
                    best = max(best, suf[i] - dp[i+x][nextM]);
                }
                dp[i][m] = best;
            }
        }
        return dp[0][1];
    }
};