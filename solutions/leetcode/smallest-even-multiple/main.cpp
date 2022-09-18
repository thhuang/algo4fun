class Solution {
   public:
    int smallestEvenMultiple(int n) {
        if (n & 1) n *= 2;
        return n;
    }
};
