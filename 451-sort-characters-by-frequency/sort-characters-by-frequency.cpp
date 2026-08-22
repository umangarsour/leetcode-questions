class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c : s)
            freq[c]++;

        int n = s.size();
        vector<vector<char>> buckets(n+1);
        for(auto& [ch, cnt] : freq){
            buckets[cnt].push_back(ch);
        }

        string result;
        for(int cnt=n;cnt>=1;cnt--){
            for(char ch : buckets[cnt]){
                result.append(cnt, ch);            
            }
        }
        return result;
    }
};