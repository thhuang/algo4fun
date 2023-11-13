class Solution {
    unordered_map<char, bool> open = {{'(', true}, {'*', true}};
    unordered_map<char, bool> close = {{')', true}, {'*', true}};

   public:
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') dp[i][i] = true;
        }
        for (int i = 1; i < n; ++i) {
            if (open[s[i - 1]] && close[s[i]]) dp[i - 1][i] = true;
        }

        for (int d = 2; d < n; ++d) {
            for (int i = 0, r = i + d; r < n; ++i, ++r) {
                for (int j = i + 1; j <= r; ++j) {
                    if (s[i] == '*' && dp[i + 1][r]) {
                        dp[i][r] = true;
                        break;
                    }
                    if (!open[s[i]] || !close[s[j]]) {
                        continue;
                    }
                    bool left = (i + 1 > j - 1) || dp[i + 1][j - 1];
                    bool right = (j + 1 > r) || dp[j + 1][r];
                    if (left && right) {
                        dp[i][r] = true;
                        break;
                    }
                }
            }
        }

        return dp.front().back();
    }
};

class Solution {
   public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;
        for (char c : s) {
            c == '(' ? ++mn : --mn;
            c == ')' ? --mx : ++mx;
            if (mx < 0) return false;
            mn = max(0, mn);
        }
        return mn == 0;
    }
};
