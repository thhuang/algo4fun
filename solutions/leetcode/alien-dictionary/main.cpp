class Solution {
   public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        if (words.size() == 1) {
            for (char c : words.front()) adj[c];
            string result;
            for (const auto& p : adj) result.push_back(p.first);
            return result;
        }

        for (int k = 1; k < words.size(); ++k) {
            string& s0 = words[k - 1];
            string& s1 = words[k];

            int i = 0, j = 0;
            while (i < s0.size() && j < s1.size() && s0[i] == s1[j]) {
                adj[s0[i]], ++i, ++j;
            }

            if (i < s0.size()) {
                if (j == s1.size()) return "";
                adj[s0[i]].insert(s1[j]);
            }

            while (i < s0.size()) adj[s0[i++]];
            while (j < s1.size()) adj[s1[j++]];
        }

        string rdag;
        unordered_map<char, int> vis;
        function<bool(char)> dfs = [&](char u) -> bool {
            vis[u] = 1;
            for (char v : adj[u]) {
                if (vis[v] == 2) continue;
                if (vis[v] == 1 || !dfs(v)) return false;
            }
            vis[u] = 2;
            rdag.push_back(u);
            return true;
        };

        for (const auto& p : adj) {
            if (vis[p.first]) continue;
            if (!dfs(p.first)) return "";
        }

        return {rdag.rbegin(), rdag.rend()};
    }
};
