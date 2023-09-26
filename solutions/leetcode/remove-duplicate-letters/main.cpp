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
            char c = s[i];

            if (seen[c - 'a']) continue;

            while (!result.empty() && result.back() > c &&
                   charLastIndex[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }

            seen[c - 'a'] = true;
            result.push_back(c);
        }

        return result;
    }
};
