class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string w : wordDict) words.insert(w);

        vector<bool> valid(s.size(), false);
        for (int r = 0; r < s.size(); ++r) {
            if (words.count(s.substr(0, r - 0 + 1))) {
                valid[r] = true;
                continue;
            }

            for (int l = 1; l <= r; ++l) {
                if (!valid[l - 1]) continue;
                if (words.count(s.substr(l, r - l + 1))) {
                    valid[r] = true;
                    break;
                }
            }
        }

        return valid.back();
    }
};

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> valid(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int r = 1; r <= s.size(); ++r) {
            for (int l = 0; l < r; ++l) {
                if (dp[l] && valid.count(s.substr(l, r - l))) {
                    dp[r] = true;
                    break;
                }
            }
        }

        return dp.back();
    }
};

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> valid(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            string t = s.substr(0, i);
            for (string_view sv(t); sv.size(); sv.remove_prefix(1)) {
                if (!dp[t.size() - sv.size()]) continue;
                if (valid.count(sv) == 0) continue;
                dp[i] = true;
                break;
            }
        }

        return dp.back();
    }
};
