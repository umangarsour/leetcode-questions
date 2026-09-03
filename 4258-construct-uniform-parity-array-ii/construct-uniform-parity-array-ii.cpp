class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        long long minOdd = LLONG_MAX, minEven = LLONG_MAX;
        bool hasOdd = false;
        for(int x : nums1){
            if(x % 2 == 0) minEven = min(minEven, (long long)x);
            else { minOdd = min(minOdd, (long long)x); hasOdd = true; }
        }

        bool allOdd = (minEven == LLONG_MAX) || (minOdd < minEven);
        bool allEven = !hasOdd;

        return allOdd || allEven;
    }
};