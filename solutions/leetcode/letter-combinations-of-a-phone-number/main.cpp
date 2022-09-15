class Solution {
    const unordered_map<char, string> digit2char = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

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

            for (char c : digit2char.at(digits[i])) {
                curr.push_back(c);
                dfs(i + 1);
                curr.pop_back();
            }
        };

        dfs(0);

        return result;
    }
};
