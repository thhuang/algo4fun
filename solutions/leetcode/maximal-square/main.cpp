class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<int> dp(n + 1, 0);

        int mx_len = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> new_dp(n + 1, 0);

            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    new_dp[j + 1] = min(dp[j], min(new_dp[j], dp[j + 1])) + 1;
                }
            }

            dp = move(new_dp);
            mx_len = max(mx_len, *max_element(dp.begin(), dp.end()));
        }

        return mx_len * mx_len;
    }
};

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<int> dp(n, 0);

        int result = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> dpNew(n);
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    dpNew[j] = 0;
                } else {
                    dpNew[j] =
                        1 +
                        min(dp[j], j == 0 ? 0 : min(dp[j - 1], dpNew[j - 1]));
                }
                result = max(result, dpNew[j]);
            }
            dp = move(dpNew);
        }

        return result * result;
    }
};

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<int> dp(n + 1, 0);

        int result = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> dpNew(n + 1, 0);
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') continue;
                dpNew[j] = 1 + min(dp[j], min(dp[j + 1], dpNew[j + 1]));
                result = max(result, dpNew[j]);
            }
            dp = move(dpNew);
        }

        return result * result;
    }
};
