class Solution {
   public:
    string minWindow(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        for (int j = 0; j < n2; ++j) {
            for (int i = 0; i < n1; ++i) {
                if (s1[i] != s2[j]) {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                } else if (j == 0) {
                    dp[i + 1][j + 1] = i;
                } else {
                    dp[i + 1][j + 1] = dp[i][j];
                }
            }
        }

        string result;
        for (int r = 0; r < n1; ++r) {
            int l = dp[r + 1].back();
            if (l == -1) continue;
            if (result.empty() || r - l + 1 < result.size())
                result = s1.substr(l, r - l + 1);
        }

        return result;
    }
};

class Solution {
   public:
    string minWindow(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<int> dp(n1 + 1, -1);
        for (int j = 0; j < n2; ++j) {
            vector<int> new_dp(n1 + 1, -1);
            for (int i = 0; i < n1; ++i) {
                if (s1[i] != s2[j]) {
                    new_dp[i + 1] = new_dp[i];
                } else if (j == 0) {
                    new_dp[i + 1] = i;
                } else {
                    new_dp[i + 1] = dp[i];
                }
            }
            dp = move(new_dp);
        }

        string result;
        for (int r = 0; r < n1; ++r) {
            int l = dp[r + 1];
            if (l == -1) continue;
            if (result.empty() || r - l + 1 < result.size())
                result = s1.substr(l, r - l + 1);
        }

        return result;
    }
};
