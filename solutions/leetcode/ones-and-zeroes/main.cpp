class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(
            strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 0; i < strs.size(); ++i) {
            int one = 0;
            for (char c : strs[i]) one += c == '1';
            int zero = int(strs[i].size()) - one;

            for (int z = 0; z <= m; ++z) {
                for (int o = 0; o <= n; ++o) {
                    dp[i + 1][z][o] = dp[i][z][o];
                    if (z - zero < 0 || o - one < 0) continue;
                    dp[i + 1][z][o] =
                        max(dp[i + 1][z][o], 1 + dp[i][z - zero][o - one]);
                }
            }
        }

        return dp.back().back().back();
    }
};

class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); ++i) {
            int one = 0;
            for (char c : strs[i]) one += c == '1';
            int zero = int(strs[i].size()) - one;

            vector<vector<int>> new_dp(m + 1, vector<int>(n + 1, 0));
            for (int z = 0; z <= m; ++z) {
                for (int o = 0; o <= n; ++o) {
                    new_dp[z][o] = dp[z][o];
                    if (z - zero < 0 || o - one < 0) continue;
                    new_dp[z][o] = max(new_dp[z][o], 1 + dp[z - zero][o - one]);
                }
            }
            dp = move(new_dp);
        }

        return dp.back().back();
    }
};
