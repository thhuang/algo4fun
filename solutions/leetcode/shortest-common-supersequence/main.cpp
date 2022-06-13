class Solution {
    struct Entry {
        int i = -1, j = -1;
        char c = ' ';
        int length = 0;
    };

   public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<Entry>> dp(n1 + 1, vector<Entry>(n2 + 1));
        for (int i = 0; i < n1; ++i) dp[i + 1][0] = {i, 0, str1[i], i + 1};
        for (int j = 0; j < n2; ++j) dp[0][j + 1] = {0, j, str2[j], j + 1};
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                char c1 = str1[i], c2 = str2[j];
                if (c1 == c2) {
                    dp[i + 1][j + 1] = {i, j, c1, dp[i][j].length + 1};
                } else {
                    const auto& a = dp[i][j + 1];
                    const auto& b = dp[i + 1][j];
                    if (a.length < b.length) {
                        dp[i + 1][j + 1] = {i, j + 1, c1, a.length + 1};
                    } else {
                        dp[i + 1][j + 1] = {i + 1, j, c2, b.length + 1};
                    }
                }
            }
        }

        string result;
        int i = n1, j = n2;
        while (~i && ~j) {
            const auto& e = dp[i][j];
            result += e.c;
            i = e.i, j = e.j;
        }

        return {++result.rbegin(), result.rend()};
    }
};

class Solution {
   public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (str1[i] == str2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        string result;
        for (int i = n1, j = n2; i > 0 || j > 0;) {
            if (i == 0) {
                result += str2[j - 1];
                --j;
            } else if (j == 0) {
                result += str1[i - 1];
                --i;
            } else if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                --i, --j;
            } else if (dp[i][j] == dp[i - 1][j]) {
                result += str1[i - 1];
                --i;
            } else {  // dp[i][j] == dp[i][j - 1]
                result += str2[j - 1];
                --j;
            }
        }

        return {result.rbegin(), result.rend()};
    }
};
