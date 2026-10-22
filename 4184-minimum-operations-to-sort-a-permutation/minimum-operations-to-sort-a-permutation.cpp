class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int k = nums[0];
        bool ok = true;
        for (int i = 0; i < n && ok; i++)
            if (nums[i] != (k + i) % n) ok = false;
        if (ok) return k == 0 ? 0 : min(n - k, k + 2);

        k = ((n - 1 - nums[0]) % n + n) % n;
        ok = true;
        for (int i = 0; i < n && ok; i++)
            if (nums[i] != ((n - 1 - i - k) % n + n) % n) ok = false;
        if (ok) return min(k, n - k) + 1;

        return -1;
    }
};