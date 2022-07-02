class Solution {
   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> valid;
        for (const string& w : wordDict) valid.emplace(w);

        int n = s.size();
        vector<vector<int>> dp(n);
        for (int r = 0; r < n; ++r) {
            string sub = s.substr(0, r + 1);
            string_view sv(sub);
            for (int l = 0; l <= r; ++l, sv.remove_prefix(1)) {
                if (l != 0 && dp[l - 1].empty()) continue;
                if (valid.count(sv) == 0) continue;
                dp[r].push_back(l);
            }
        }

        vector<string> result;
        vector<int> starts;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == -1) {
                string sentance;
                for (auto it = starts.rbegin(); it != prev(starts.rend()); ++it) {
                    sentance += s.substr(*it, *next(it) - *it) + " ";
                }
                sentance += s.substr(*starts.begin());
                result.push_back(sentance);
                return;
            }

            for (int v : dp[i]) {
                starts.push_back(v);
                dfs(v - 1);
                starts.pop_back();
            }
        };

        dfs(n - 1);

        return result;
    }
};
