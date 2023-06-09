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

class Solution {
   public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_set<char> char1, char2;
        unordered_map<char, int> charCount1, charCount2;
        for (char c : word1) ++charCount1[c], char1.insert(c);
        for (char c : word2) ++charCount2[c], char2.insert(c);

        if (char1 != char2) return false;

        unordered_map<int, int> countChar1, countChar2;
        for (auto [_, cnt] : charCount1) ++countChar1[cnt];
        for (auto [_, cnt] : charCount2) ++countChar2[cnt];

        for (auto [cnt, chs] : countChar1) {
            if (countChar2[cnt] != chs) return false;
        }
        return true;
    }
};
