class Solution {
   public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int sz = cuts.size();

        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        for (int d = 2; d < sz; ++d) {
            for (int l = 0; l + d < sz; ++l) {
                int r = l + d;
                int v = numeric_limits<int>::max();
                for (int m = l + 1; m < r; ++m) {
                    v = min(v, dp[l][m] + dp[m][r] + cuts[r] - cuts[l]);
                }
                dp[l][r] = v;
            }
        }

        return dp.front().back();
    }
};
