class Solution {
   public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j) dp[0][j] = j;

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {  // word1[i - 1] != word2[j - 1]
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }

        return dp.back().back();
    }
};

class Solution {
   public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));

        for (int i = 0; i <= word1.size(); ++i) {
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                    continue;
                }

                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {  // word1[i - 1] != word2[j - 1]
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }

        return dp.back().back();
    }
};

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 1; i <= m; ++i) {
            vector<int> dpNew(n + 1);
            dpNew[0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dpNew[j] = dp[j - 1];
                } else {
                    dpNew[j] = min({dp[j - 1], dp[j], dpNew[j - 1]}) + 1;
                }
            }
            dp = move(dpNew);
        }

        return dp.back();
    }
};

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<int> dp(n2 + 1);

        for (int i = n1; i >= 0; --i) {
            vector<int> dpNew(n2 + 1);

            for (int j = n2; j >= 0; --j) {
                if (i == n1 || j == n2) {
                    dpNew[j] = n1 + n2 - i - j;
                    continue;
                }

                if (word1[i] == word2[j]) {
                    dpNew[j] = dp[j + 1];
                } else {
                    dpNew[j] = 1 + min(dpNew[j + 1], min(dp[j + 1], dp[j]));
                }
            }

            dp = move(dpNew);
        }

        return dp[0];
    }
};
