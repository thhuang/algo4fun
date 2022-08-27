class Solution {
   public:
    int maxPower(string s) {
        char p = ' ';
        int result = 0, cnt = 0;
        for (char c : s) {
            if (c != p) p = c, cnt = 0;
            result = max(result, ++cnt);
        }
        return result;
    }
};
