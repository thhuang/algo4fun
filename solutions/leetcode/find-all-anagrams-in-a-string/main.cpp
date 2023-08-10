class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> char_count;
        for (char c : p) --char_count[c];

        vector<int> result;
        int k = p.size();
        int score = k;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            score -= abs(char_count[c]);
            ++char_count[c];
            score += abs(char_count[c]);

            if (i >= k) {
                char r = s[i - k];
                score -= abs(char_count[r]);
                --char_count[r];
                score += abs(char_count[r]);
            }

            if (score == 0) result.push_back(i - k + 1);
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();

        unordered_map<char, int> mp;
        for (char c : p) ++mp[c];

        int k = 0;
        vector<int> result;
        for (int r = 0, l = r - n + 1; r < s.size(); ++r, ++l) {
            if (mp.count(s[r]) > 0) {
                if (--mp[s[r]] >= 0) ++k;
            }

            if (k == n) result.push_back(l);

            if (l >= 0 && mp.count(s[l]) > 0) {
                if (++mp[s[l]] > 0) --k;
            }
        }

        return result;
    }
};
