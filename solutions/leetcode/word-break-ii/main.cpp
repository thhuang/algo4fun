class Solution {
   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string_view> valid(wordDict.begin(), wordDict.end());

        vector<vector<int>> dp(n);
        for (int r = 0; r < n; ++r) {
            string sub = s.substr(0, r + 1);
            string_view w(sub);
            if (valid.count(w)) dp[r].push_back(0);
            for (int l = 1; l <= r; ++l) {
                w.remove_prefix(1);
                if (dp[l - 1].size() && valid.count(w)) dp[r].push_back(l);
            }
        }

        vector<string> result;
        deque<int> breakpoints;
        function<void(int)> dfs = [&](int r) -> void {
            if (r < 0) {
                string sentence;
                for (int i = 0; i < breakpoints.size() - 1; ++i) {
                    int l = breakpoints[i];
                    int r = breakpoints[i + 1];
                    sentence += s.substr(l, r - l) + " ";
                }
                sentence += s.substr(breakpoints.back());
                result.push_back(sentence);
                return;
            }

            for (int l : dp[r]) {
                breakpoints.push_front(l);
                dfs(l - 1);
                breakpoints.pop_front();
            }
        };

        dfs(n - 1);

        return result;
    }
};
