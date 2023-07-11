class Solution {
   public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());

        int n = houses.size();

        vector<vector<int>> cache(n, vector<int>(n, -1));
        auto calculate = [&](int l, int r) -> int {
            if (~cache[l][r]) return cache[l][r];

            int t = houses[l + (r - l) / 2];

            int result = 0;
            for (int i = l; i <= r; ++i) result += abs(houses[i] - t);
            return cache[l][r] = result;
        };

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        function<int(int, int)> dfs = [&](int hi, int ki) -> int {
            if (hi == n) return 0;
            if (ki == 1) return calculate(hi, n - 1);
            if (~dp[hi][ki]) return dp[hi][ki];

            int v = numeric_limits<int>::max();
            for (int i = hi; i < n; ++i) {
                v = min(v, calculate(hi, i) + dfs(i + 1, ki - 1));
            }
            return dp[hi][ki] = v;
        };

        return dfs(0, k);
    }
};

class Solution {
   public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());

        int n = houses.size();

        vector<vector<int>> dist(n, vector<int>(n));
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                int t = houses[l + (r - l) / 2];
                int v = 0;
                for (int i = l, j = r; i < j; ++i, --j)
                    v += houses[j] - houses[i];
                dist[l][r] = v;
            }
        }

        vector<int> dp = dist[0];
        for (int i = 2; i <= k; ++i) {
            for (int r = n - 1; ~r; --r) {
                for (int l = 0; l < r; ++l) {
                    dp[r] = min(dp[r], dp[l] + dist[l + 1][r]);
                }
            }
        }

        return dp.back();
    }
};
