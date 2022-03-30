class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = size(s1);
        unordered_map<char, int> chars;
        for (char c : s1) ++chars[c];

        for (int l = 0, r = 0; r < size(s2); ++r) {
            while (chars[s2[r]] == 0 && l < r) {
                ++chars[s2[l++]];
            }

            if (chars[s2[r]] > 0) {
                --chars[s2[r]];
                if (r - l + 1 == n) return true;
                continue;
            }

            ++l;
        }
        return false;
    }
};
