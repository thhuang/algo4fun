class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        string result;

        int mn = min(word1.size(), word2.size());
        for (int i = 0; i < mn; ++i) {
            result += word1[i];
            result += word2[i];
        }

        string &word = word1.size() > word2.size() ? word1 : word2;
        for (int i = mn; i < word.size(); ++i) {
            result += word[i];
        }

        return result;
    }
};
