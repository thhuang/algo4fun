class Solution {
   public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> char2idx;
        for (int i = 0; i < keyboard.size(); ++i) {
            char2idx[keyboard[i]] = i;
        }

        int result = 0;
        for (int i = 0, p = 0; i < word.size(); ++i) {
            int q = char2idx[word[i]];
            result += abs(p - q);
            p = q;
        }

        return result;
    }
};
