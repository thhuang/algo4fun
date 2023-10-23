class Solution {
   public:
    int numWays(int n, int k) {
        int same = 0, diff = k;
        for (int i = 1; i < n; ++i) {
            tie(same, diff) = make_pair(diff, (same + diff) * (k - 1));
        }
        return same + diff;
    }
};
