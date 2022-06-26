class Solution {
    const int mod = 1e9 + 7;

   public:
    int distinctSequences(int n) {
        vector<vector<int>> valid = {
            {},        {2, 3, 4, 5, 6}, {1, 3, 5}, {1, 2, 4, 5},
            {1, 3, 5}, {1, 2, 3, 4, 6}, {1, 5}};

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(7, vector<int>(7, 0)));
        for (int i = 1; i <= 6; ++i) dp[0][i][i] = 1;
        for (int i = 1; i < n; ++i) {
            for (int p0 = 1; p0 <= 6; ++p0) {
                for (int p1 : valid[p0]) {
                    long long v = 0;
                    for (int p2 = 1; p2 <= 6; ++p2) {
                        if (p2 == p0) continue;
                        v = (v + dp[i - 1][p1][p2]) % mod;
                    }
                    dp[i][p0][p1] = v;
                }
            }
        }

        long long result = 0;
        for (int i = 1; i <= 6; ++i) {
            for (int j = 1; j <= 6; ++j) {
                result = (result + dp.back()[i][j]) % mod;
            }
        }

        return result;
    }
};
