class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            long long a = q[0], b = q[1];
            int depthA = 0, depthB = 0;
            while (a != b) {
                if (a > b) { a /= 2; depthA++; }
                else { b /= 2; depthB++; }
            }
            ans.push_back(depthA + depthB + 1);
        }
        return ans;
    }
};