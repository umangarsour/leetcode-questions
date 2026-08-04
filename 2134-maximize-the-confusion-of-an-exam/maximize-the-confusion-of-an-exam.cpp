class Solution {
public:
    int longestWindow(string &s, char target, int k){
        int n = s.size(), left = 0, right = 0, count = 0, ans = 0;
        for(int right=0;right<n;right++){
            if(s[right] != target) count++;
            while(count > k){
                if(s[left] != target) count--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(longestWindow(answerKey, 'T', k), longestWindow(answerKey, 'F', k));
    }
};