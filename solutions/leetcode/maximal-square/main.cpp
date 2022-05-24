class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix.front().size();

        vector<int> prev(m, 0);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') continue;
                curr[j] = 1;
                if (j > 0) curr[j] += min({prev[j], prev[j - 1], curr[j - 1]});
                result = max(result, curr[j] * curr[j]);
            }
            prev = move(curr);
        }

        return result;
    }
};

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        int result = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            vector<int> new_dp(n, 0);
            new_dp[0] = matrix[i][0] == '1';
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '0') continue;
                new_dp[j] = 1 + min(new_dp[j - 1], min(dp[j - 1], dp[j]));
            }
            dp = move(new_dp);
            result = max(result, *max_element(dp.begin(), dp.end()));
        }

        return result * result;
    }
};
