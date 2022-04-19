class Solution {
    unordered_map<char, vector<char>> digit2letters = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};

   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        string s;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == digits.size()) {
                result.push_back(s);
                return;
            }
            for (char c : digit2letters[digits[i]]) {
                s.push_back(c);
                dfs(i + 1);
                s.pop_back();
            }
        };
        dfs(0);
        return result;
    }
};
