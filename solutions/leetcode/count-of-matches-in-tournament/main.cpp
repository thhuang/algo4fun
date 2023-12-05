class Solution {
   public:
    int numberOfMatches(int n) {
        int result = 0;
        while (n > 1) {
            result += n / 2;
            if (n & 1) ++n;
            n /= 2;
        }
        return result;
    }
};
