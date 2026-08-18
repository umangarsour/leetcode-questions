class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        for(int x : nums){
            int cnt = 0;
            for(int s=0;s+k <= n;s++){
                bool found = false;
                for(int i=s;i<s+k;i++){
                    if(nums[i] == x){
                        found = true;
                        break;
                    }
                }
                if(found) cnt++;
            }
            if(cnt == 1) ans = max(ans, x);
        }
        return ans;
    }
};