class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        long axorb = 0;
        for (long v : nums) {
            v -= numeric_limits<int>::min();
            axorb ^= v;
        }

        long mask = axorb - (axorb & (axorb - 1));

        long a = 0;
        for (long v : nums) {
            v -= numeric_limits<int>::min();
            if (v & mask) a ^= v;
        }

        int aa = a + numeric_limits<int>::min();
        int bb = axorb ^ a + numeric_limits<int>::min();

        return {aa, bb};
    }
};
