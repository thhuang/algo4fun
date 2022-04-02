class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        int n = min(size(word1), size(word2));

        string ans = "";
        for (int i = 0; i < n; ++i) ans += word1[i], ans += word2[i];

        string& word = size(word1) > size(word2) ? word1 : word2;
        for (int i = n; i < size(word); ++i) ans += word[i];

        return ans;
    }
};
