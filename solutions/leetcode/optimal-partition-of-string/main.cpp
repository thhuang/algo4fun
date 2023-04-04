class Solution {
   public:
    int partitionString(string s) {
        int n = s.size();
        int result = 0;
        array<bool, 26> seen;

        for (int l = 0; l < n;) {
            fill(seen.begin(), seen.end(), false);
            ++result;

            int r = l;
            while (r < n && !seen[s[r] - 'a']) {
                seen[s[r] - 'a'] = true;
                ++r;
            }

            l = r;
        }

        return result;
    }
};
