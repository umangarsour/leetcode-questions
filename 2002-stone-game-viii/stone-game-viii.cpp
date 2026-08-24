class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> prefixSum(n+1, 0);
        for(int i=0;i<n;i++){
            prefixSum[i+1] = prefixSum[i] + stones[i];
        }
        long long hNext = 0;
        long long running = LLONG_MIN;
        long long hi = 0;

        for(int i=n-1;i>=1;i--){
            int j = i + 1;
            long long f = prefixSum[j] - hNext;
            running = max(running, f);
            hi = running;
            hNext = hi;
        }
        return hi;
    }
};