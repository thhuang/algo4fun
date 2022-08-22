class Solution {
   public:
    int trailingZeroes(int n) {
        int five = 0;
        while (n) five += n /= 5;
        return five;
    }
};
