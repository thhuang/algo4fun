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
        int t = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(t + 1));
    }
};
