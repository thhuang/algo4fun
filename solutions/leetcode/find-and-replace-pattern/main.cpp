class Solution {
   public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        vector<string> result;
        for (const string& w : words) {
            if (check(w, pattern)) result.push_back(w);
        }
        return result;
    }

    bool check(const string& word, const string& pattern) {
        array<bool, 26> seen_word_char;
        array<bool, 26> seen_pattern_char;
        fill(seen_word_char.begin(), seen_word_char.end(), false);
        fill(seen_pattern_char.begin(), seen_pattern_char.end(), false);

        array<int, 26> mp;
        for (int i = 0; i < pattern.size(); ++i) {
            int c = word[i] - 'a', p = pattern[i] - 'a';
            if (seen_word_char[c]) {
                if (mp[c] != p) return false;
            } else {
                if (seen_pattern_char[p]) return false;
                mp[c] = p;
                seen_word_char[c] = true;
                seen_pattern_char[p] = true;
            }
        }

        return true;
    }
};
