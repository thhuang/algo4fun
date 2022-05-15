class Solution {
   public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> word_char_count(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                ++word_char_count[i][c - 'a'];
            }
        }

        vector<string> result;
        for (int i = 0; i < words.size(); ++i) {
            result.push_back(words[i]);

            for (int j = i + 1; j < words.size(); ++j) {
                int is_anagram = true;
                for (int k = 0; k < 26; ++k) {
                    if (word_char_count[i][k] != word_char_count[j][k]) {
                        is_anagram = false;
                        break;
                    }
                }
                if (!is_anagram) break;
                i = j;
            }
        }

        return result;
    }
};
