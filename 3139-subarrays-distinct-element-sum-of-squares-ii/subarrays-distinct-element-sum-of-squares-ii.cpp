class Solution {
    static const long long MOD = 1e9 + 7;
    vector<long long> sum, lazy;

    void push(int node, int l, int r) {
        if (lazy[node]) {
            int m = (l + r) / 2;
            apply(node * 2, l, m, lazy[node]);
            apply(node * 2 + 1, m + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }
    void apply(int node, int l, int r, long long v) {
        sum[node] = (sum[node] + v * (r - l + 1)) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }
    long long queryAdd(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) {
            long long res = sum[node];
            apply(node, l, r, 1);
            return res;
        }
        push(node, l, r);
        int m = (l + r) / 2;
        long long res = queryAdd(node * 2, l, m, ql, qr)
                      + queryAdd(node * 2 + 1, m + 1, r, ql, qr);
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        return res % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        unordered_map<int, int> last;
        long long ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int p = last.count(nums[i]) ? last[nums[i]] : -1;
            long long s = queryAdd(1, 0, n - 1, p + 1, i);
            cur = (cur + 2 * s + (i - p)) % MOD;
            ans = (ans + cur) % MOD;
            last[nums[i]] = i;
        }
        return (int)ans;
    }
};