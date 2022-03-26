class Solution {
   public:
    int countOdds(int low, int high) {
        int result = (high - low) / 2;
        if (low & 1 || high & 1) return result + 1;
        return result;
    }
};
