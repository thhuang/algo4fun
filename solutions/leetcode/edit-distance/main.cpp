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
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
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
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }

        return dp.back().back();
    }
};

class Solution {
   public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size() + 1);

        for (int i = 0; i <= word1.size(); ++i) {
            vector<int> new_dp(word2.size() + 1);
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0 || j == 0) {
                    new_dp[j] = i + j;
                    continue;
                }
                if (word1[i - 1] == word2[j - 1]) {
                    new_dp[j] = dp[j - 1];
                } else {  // word1[i - 1] != word2[j - 1]
                    new_dp[j] = 1 + min({dp[j], new_dp[j - 1], dp[j - 1]});
                }
            }
            dp = move(new_dp);
        }

        return dp.back();
    }
};
