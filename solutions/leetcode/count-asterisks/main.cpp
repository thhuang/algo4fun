class Solution {
   public:
    int countAsterisks(string s) {
        int result = 0;
        bool count = true;
        for (char c : s) {
            if (c == '|') {
                count = !count;
            } else if (c == '*' && count) {
                ++result;
            }
        }
        return result;
    }
};
