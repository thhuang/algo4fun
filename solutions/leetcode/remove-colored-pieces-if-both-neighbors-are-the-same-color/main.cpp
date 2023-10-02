class Solution {
   public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        for (int l = 0, r = 0; r <= colors.size(); ++r) {
            if (r == colors.size() || colors[l] != colors[r]) {
                int len = r - l;
                (colors[l] == 'A' ? a : b) += max(0, r - l - 2);
                l = r;
            }
        }
        return a > b;
    }
};
