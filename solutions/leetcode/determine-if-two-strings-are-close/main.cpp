class Solution {
   public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> freq1, freq2;
        for (char c : word1) ++freq1[c];
        for (char c : word2) ++freq2[c];
        if (freq1.size() != freq2.size()) return false;

        unordered_map<int, int> cnt;
        for (auto [c, n] : freq1) {
            if (freq2.count(c) == 0) return false;
            ++cnt[n];
        }

        for (auto [_, n] : freq2) {
            if (--cnt[n] < 0) return false;
        }

        return true;
    }
};
