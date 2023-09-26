class Solution {
   public:
    string removeDuplicateLetters(string s) {
        array<int, 26> charLastIndex = {};
        for (int i = 0; i < s.size(); ++i) {
            charLastIndex[s[i] - 'a'] = i;
        }

        array<bool, 26> seen = {};

        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (seen[s[i] - 'a']) continue;

            while (!result.empty() && result.back() > s[i] &&
                   charLastIndex[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }

            seen[s[i] - 'a'] = true;
            result.push_back(s[i]);
        }

        return result;
    }
};
