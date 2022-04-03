class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string w : wordDict) dict.insert(w);

        vector<bool> valid(size(s), false);
        for (int i = 0; i < size(s); ++i) {
            if (dict.count(s.substr(0, i + 1))) {
                valid[i] = true;
                continue;
            }

            for (int j = 0; j < i; ++j) {
                if (!valid[j]) continue;
                if (dict.count(s.substr(j + 1, i - j))) {
                    valid[i] = true;
                    break;
                }
            }
        }
        return valid.back();
    }
};
