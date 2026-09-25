class Solution {
public:
    string s;
    int i = 0;

    set<string> parse() {
        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                for (auto &word : current)
                    result.insert(word);
                current = {""};
                i++;
            } else {
                set<string> next;

                if (s[i] == '{') {
                    i++;
                    next = parse();
                    i++;
                } else {
                    next.insert(string(1, s[i]));
                    i++;
                }

                set<string> temp;

                for (auto &a : current) {
                    for (auto &b : next) {
                        temp.insert(a + b);
                    }
                }

                current = temp;
            }
        }

        for (auto &word : current)
            result.insert(word);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parse();

        return vector<string>(ans.begin(), ans.end());
    }
};