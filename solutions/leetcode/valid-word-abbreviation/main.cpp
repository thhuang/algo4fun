class Solution {
   public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (!isdigit(abbr[j])) {
                if (word[i] != abbr[j]) return false;
                ++i, ++j;
                continue;
            }
            if (abbr[j] == '0') return false;

            int v = 0;
            while (isdigit(abbr[j])) {
                v = v * 10 + (abbr[j++] - '0');
            }
            i += v;
        }
        return i == word.size() && j == abbr.size();
    }
};
