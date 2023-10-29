class Solution {
   public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest / minutesToDie;
        int i = 0, v = 1;
        while (v < buckets) v *= (t + 1), ++i;
        return i;
    }
};

class Solution {
   public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = minutesToTest / minutesToDie;
        int states = tests + 1;
        // states^x >= buckets
        return ceil(log2(buckets) / log2(states));
    }
};
