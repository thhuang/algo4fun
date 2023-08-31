class Solution {
   public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> reach(n + 1);
        iota(reach.begin(), reach.end(), 0);
        for (int i = 0; i <= n; ++i) {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            reach[l] = r;
        }

        int result = 0;
        for (int i = 0, currEnd = 0, nextEnd = 0; i <= n; ++i) {
            if (i > nextEnd) return -1;
            if (i > currEnd) {
                currEnd = nextEnd;
                ++result;
            }
            nextEnd = max(nextEnd, reach[i]);
        }

        return result;
    }
};
