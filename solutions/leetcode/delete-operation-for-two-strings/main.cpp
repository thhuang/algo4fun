class Solution {
   public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1,
                               vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); ++i) dp[i][0] = i;
        for (int j = 1; j <= word2.size(); ++j) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                char c1 = word1[i - 1], c2 = word2[j - 1];
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp.back().back();
    }
};

class Solution {
   public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size() + 1, 0);
        for (int i = 0; i <= word1.size(); ++i) {
            vector<int> new_dp(word2.size() + 1, 0);
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0 || j == 0) {
                    new_dp[j] = i + j;
                } else if (word1[i - 1] == word2[j - 1]) {
                    new_dp[j] = dp[j - 1];
                } else {
                    new_dp[j] = 1 + min(new_dp[j - 1], dp[j]);
                }
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int> dp(n2 + 1, 0);
        for (int j = 1; j <= n2; ++j) dp[j] = j;
        for (int i = 0; i < n1; ++i) {
            vector<int> new_dp(n2 + 1, i + 1);
            for (int j = 0; j < n2; ++j) {
                if (word1[i] == word2[j]) {
                    new_dp[j + 1] = dp[j];
                } else {
                    new_dp[j + 1] = 1 + min(dp[j + 1], new_dp[j]);
                }
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};
