class Solution {
   public:
    int countPalindromicSubsequence(string s) {
        array<vector<int>, 26> charIndices = {};
        for (int i = 0; i < s.size(); ++i) {
            charIndices[s[i] - 'a'].push_back(i);
        }

        int result = 0;
        for (const vector<int>& indices : charIndices) {
            if (indices.size() < 2) continue;
            unordered_set<char> chars;
            for (int i = indices.front() + 1; i < indices.back(); ++i) {
                chars.insert(s[i]);
            }
            result += chars.size();
        }

        return result;
    }
};
