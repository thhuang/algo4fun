class Solution {
   public:
    int minOperations(string s) {
        int result01 = 0, result10 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i % 2 == 0) {
                s[i] == '0' ? ++result10 : ++result01;
            } else {
                s[i] == '1' ? ++result10 : ++result01;
            }
        }
        return min(result01, result10);
    }
};
