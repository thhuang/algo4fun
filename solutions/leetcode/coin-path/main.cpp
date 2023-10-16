class Solution {
    const int mx = numeric_limits<int>::max();

   public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();

        vector<vector<int>> path(n);
        path[0] = {1};

        vector<int> dp(n, mx);
        dp[0] = coins[0];

        for (int r = 1; r < n; ++r) {
            if (coins[r] == -1) continue;

            for (int l = max(0, r - maxJump); l < r; ++l) {
                if (dp[l] == mx) continue;

                int c = dp[l] + coins[r];
                if (c > dp[r]) continue;

                vector<int> newPath = path[l];
                newPath.push_back(r + 1);

                if (path[r].empty() || c < dp[r]) {
                    path[r] = newPath;
                    dp[r] = c;
                    continue;
                }

                bool smaller = true;
                for (int i = 0;
                     smaller && i < min(path[r].size(), newPath.size()); ++i) {
                    if (path[r][i] < newPath[i]) smaller = false;
                }

                if (smaller) {
                    path[r] = newPath;
                    dp[r] = c;
                }
            }
        }

        return path.back();
    }
};
