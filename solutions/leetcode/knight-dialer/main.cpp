class Solution {
    typedef long long ll;
    const int mod = 1e9 + 7;

    vector<vector<int>> prevPos = {
        {4, 6},     // 0
        {6, 8},     // 1
        {7, 9},     // 2
        {4, 8},     // 3
        {0, 3, 9},  // 4
        {},         // 5
        {0, 1, 7},  // 6
        {2, 6},     // 7
        {1, 3},     // 8
        {2, 4},     // 9
    };

   public:
    int knightDialer(int n) {
        vector<array<int, 10>> dp(n);
        fill(dp[0].begin(), dp[0].end(), 1);
        for (int i = 1; i < n; ++i) {
            for (int to = 0; to < 10; ++to) {
                for (int from : prevPos[to]) {
                    (dp[i][to] += dp[i - 1][from]) %= mod;
                }
            }
        }

        int result = 0;
        for (int v : dp.back()) {
            (result += v) %= mod;
        }

        return result;
    }
};

class Solution {
    typedef long long ll;
    const int mod = 1e9 + 7;

    vector<vector<int>> prevPos = {
        {4, 6},     // 0
        {6, 8},     // 1
        {7, 9},     // 2
        {4, 8},     // 3
        {0, 3, 9},  // 4
        {},         // 5
        {0, 1, 7},  // 6
        {2, 6},     // 7
        {1, 3},     // 8
        {2, 4},     // 9
    };

   public:
    int knightDialer(int n) {
        array<int, 10> dp;
        fill(dp.begin(), dp.end(), 1);
        for (int i = 1; i < n; ++i) {
            array<int, 10> dpNew = {};
            for (int to = 0; to < 10; ++to) {
                for (int from : prevPos[to]) {
                    (dpNew[to] += dp[from]) %= mod;
                }
            }
            dp = dpNew;
        }

        int result = 0;
        for (int v : dp) {
            (result += v) %= mod;
        }

        return result;
    }
};
