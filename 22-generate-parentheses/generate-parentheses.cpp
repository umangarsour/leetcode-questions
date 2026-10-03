class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};

        vector<string> result;
        for (int i = 0; i < n; i++) {
            vector<string> left = generateParenthesis(i);
            vector<string> right = generateParenthesis(n - 1 - i);
            for (const string& l : left) {
                for (const string& r : right) {
                    result.push_back("(" + l + ")" + r);
                }
            }
        }
        return result;
    }
};