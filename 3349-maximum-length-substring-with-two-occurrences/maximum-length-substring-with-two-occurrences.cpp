class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, maxi = 0;
        int n = s.size();
        unordered_map<char, int> freq;
        for(int r = 0; r < n; r++){
            freq[s[r]]++;
            while(freq[s[r]] > 2){
                freq[s[l]]--;
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};