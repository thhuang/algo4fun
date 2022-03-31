class Solution {
   public:
    int firstUniqChar(string s) {
        array<int, 26> counts;
        fill(counts.begin(), counts.end(), 0);

        for (char c : s) ++counts[c - 'a'];
        for (int i = 0; i < size(s); ++i) {
            if (counts[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};
