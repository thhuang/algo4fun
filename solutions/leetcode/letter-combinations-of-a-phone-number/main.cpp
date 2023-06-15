class Solution {
    vector<vector<char>> mp = {{},
                               {},
                               {'a', 'b', 'c'},
                               {'d', 'e', 'f'},
                               {'g', 'h', 'i'},
                               {'j', 'k', 'l'},
                               {'m', 'n', 'o'},
                               {'p', 'q', 'r', 's'},
                               {'t', 'u', 'v'},
                               {'w', 'x', 'y', 'z'}};

   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string curr;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == digits.size()) {
                result.push_back(curr);
                return;
            }
            for (char c : mp[digits[i] - '0']) {
                curr.push_back(c);
                dfs(i + 1);
                curr.pop_back();
            }
        };
        dfs(0);
        return result;
    }
};
