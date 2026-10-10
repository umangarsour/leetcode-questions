class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long total = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = llabs((long long)nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }
        long long K = (long long)k1 + k2;
        if (total <= K) return 0;

        auto cost = [&](long long c) {
            long long s = 0;
            for (long long d : diff) if (d > c) s += d - c;
            return s;
        };

        long long lo = 0, hi = mx;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cost(mid) <= K) hi = mid;
            else lo = mid + 1;
        }
        long long c = lo;
        long long remaining = K - cost(c);

        long long m = 0, ans = 0;
        for (long long d : diff) {
            if (d < c) ans += d * d;
            else m++;
        }
        ans += remaining * (c - 1) * (c - 1);
        ans += (m - remaining) * c * c;      
        return ans;
    }
};