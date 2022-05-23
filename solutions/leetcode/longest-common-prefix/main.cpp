class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs.front();
        for (int i = 0; i < result.size(); ++i) {
            for (string& s : strs) {
                if (i == s.size() || result[i] != s[i])
                    return result.substr(0, i);
            }
        }
        return result;
    }
};
