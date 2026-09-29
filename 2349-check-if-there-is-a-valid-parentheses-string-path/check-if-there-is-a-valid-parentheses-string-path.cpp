class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        int len = m + n - 1;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        int startBalance = (grid[0][0] == '(' ? 1 : -1);

        if (startBalance < 0)
            return false;

        dp[0][0][startBalance] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= len; balance++) {

                    bool possible = false;

                    if (i > 0)
                        possible = possible || dp[i - 1][j][balance];

                    if (j > 0)
                        possible = possible || dp[i][j - 1][balance];

                    if (!possible)
                        continue;

                    int newBalance = balance;

                    if (grid[i][j] == '(')
                        newBalance++;
                    else
                        newBalance--;

                    if (newBalance >= 0 && newBalance <= len)
                        dp[i][j][newBalance] = true;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};