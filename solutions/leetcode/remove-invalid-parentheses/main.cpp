class Solution {
    bool isValid(const string& s) {
        int opens = 0;
        for (char c : s) {
            if (c == '(') {
                ++opens;
            } else if (c == ')') {
                if (--opens < 0) return false;
            }
        }
        return opens == 0;
    }

   public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        string curr;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == s.size()) {
                if (isValid(curr)) {
                    if (result.empty() ||
                        result.begin()->size() < curr.size()) {
                        result = {curr};
                    } else if (result.begin()->size() == curr.size()) {
                        result.insert(curr);
                    }
                }
                return;
            }

            curr += s[i];
            dfs(i + 1);
            curr.pop_back();

            if (s[i] != '(' && s[i] != ')') return;

            dfs(i + 1);
        };
        dfs(0);

        return {result.begin(), result.end()};
    }
};
