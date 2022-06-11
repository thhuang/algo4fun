class Solution {
   public:
    bool matchReplacement(string s, string sub,
                          vector<vector<char>>& mappings) {
        int m = s.size();
        int n = sub.size();

        unordered_map<char, unordered_set<char>> adj;
        for (const auto& mp : mappings) adj[mp[0]].emplace(mp[1]);

        for (int i = 0; i + n <= m; ++i) {
            bool found = true;
            for (int j = 0; j < n; ++j) {
                if (s[i + j] == sub[j]) continue;
                if (adj[sub[j]].count(s[i + j])) continue;
                found = false;
            }
            if (found) return true;
        }

        return false;
    }
};
