class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> result;
        for(int x : nums2){
            if(set1.count(x)){
                result.push_back(x);
                set1.erase(x);
            }
        }
        return result;
    }
};