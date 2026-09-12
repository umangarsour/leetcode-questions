class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long,4>> iv(n);
        for(int i = 0; i < n; i++){
            iv[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(iv.begin(), iv.end(), [](auto& a, auto& b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<long long> rArr(n);
        for(int i = 0; i < n; i++) rArr[i] = iv[i][1];

        vector<int> pred(n);
        for(int i = 0; i < n; i++){
            long long li = iv[i][0];
            int p = lower_bound(rArr.begin(), rArr.end(), li) - rArr.begin();
            pred[i] = p;
        }

        using State = pair<long long, vector<int>>; 
        auto better = [](const State& a, const State& b) -> bool {
            
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second; 
        };

        vector<vector<State>> dp(n+1, vector<State>(5, {0, {}}));

        for(int i = 1; i <= n; i++){
            int idx = i - 1;
            long long w = iv[idx][2];
            long long origIdx = iv[idx][3];
            int p = pred[idx];

            for(int k = 0; k <= 4; k++){
                State skip = dp[i-1][k];
                State best = skip;
                if(k >= 1){
                    State prevState = dp[p][k-1];
                    long long newScore = prevState.first + w;
                    vector<int> newIndices = prevState.second;
                    newIndices.push_back((int)origIdx);
                    sort(newIndices.begin(), newIndices.end());
                    State takeState = {newScore, newIndices};
                    if(better(takeState, best)) best = takeState;
                }
                dp[i][k] = best;
            }
        }

        return dp[n][4].second;
    }
};