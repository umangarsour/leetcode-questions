class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        vector<int> left(n), right(n);
        int j=0;
        for(int i=0;i<n;i++){
            while(station[j] != skill[i])j++;
            left[i] = j;
            j++;
        }

        j = m-1;
        for(int i=n-1;i>=0;i--){
            while(station[j] != skill[i])j--;
            right[i] = j;
            j--;
        }

        long long ans = 0;
        for(int i=1;i<n;i++){
            ans = max(ans, (long long)right[i] - left[i-1]);
        }
        return ans;
    }
};