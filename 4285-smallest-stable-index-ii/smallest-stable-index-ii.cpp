class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> x = nums;
        vector<int>& a = x;

        int n = a.size();
        vector<int> maxi(n), mini(n);

        maxi[0] = a[0];
        for (int i = 1; i < n; i++) {
            maxi[i] = max(maxi[i - 1], a[i]);
        }

        mini[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mini[i] = min(mini[i + 1], a[i]);
        }

        for (int i = 0; i < n; i++) {
            if (maxi[i] - mini[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};