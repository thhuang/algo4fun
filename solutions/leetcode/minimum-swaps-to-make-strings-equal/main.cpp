class Solution {
   public:
    int minimumSwap(string s1, string s2) {
        int x = 0, y = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) continue;
            s1[i] == 'x' ? ++x : ++y;
        }

        if ((x + y) & 1) return -1;
        return (x + y) / 2 + (x & 1);
    }
};
