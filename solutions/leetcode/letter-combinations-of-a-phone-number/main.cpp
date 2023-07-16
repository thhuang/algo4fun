class Solution {
    vector<string> mp = {"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};

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
