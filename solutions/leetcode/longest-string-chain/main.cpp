class Solution {
   public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> cache;
        unordered_map<int, unordered_set<string>> length_words;

        int max_length = 1;
        for (string s : words) {
            int l = s.size();
            length_words[l].insert(s);
            max_length = max(max_length, l);
        }

        function<int(string, int)> dfs = [&](string s, int depth) -> int {
            if (length_words[s.size()].count(s) == 0) return depth - 1;
            if (auto it = cache.find(s); it != cache.end()) return it->second;

            int max_depth = depth;
            for (int i = 0; i < s.size(); ++i) {
                string candidate;
                for (int j = 0; j < s.size(); ++j) {
                    if (j == i) continue;
                    candidate += s[j];
                }
                max_depth = max(max_depth, dfs(candidate, depth + 1));
            }

            return cache[s] = max_depth;
        };

        int result = 0;
        for (int i = max_length; i >= 1; --i) {
            for (string s : length_words[i]) result = max(result, dfs(s, 1));
        }

        return result;
    }
};

class Solution {
   public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> valid(words.begin(), words.end());

        unordered_map<string, int> vis;
        function<int(string)> dfs = [&](string s) -> int {
            if (auto it = vis.find(s); it != vis.end()) return it->second;
            if (valid.count(s) == 0) return -1;

            int chain = 0;
            for (int i = 0; i < s.size(); ++i) {
                chain = max(chain, dfs(s.substr(0, i) + s.substr(i + 1)));
            }

            ++chain;
            vis[s] = chain;
            return chain;
        };

        int result = 0;
        for (const string& s : words) {
            if (vis.count(s)) continue;
            result = max(result, dfs(s));
        }

        return result;
    }
};

class Solution {
   public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(n);

        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[words[i].size()].push_back(i);
        }

        for (auto [len, v0] : mp) {
            auto it = mp.find(len + 1);
            if (it == mp.end()) continue;

            auto& v1 = it->second;
            for (auto i : v0) {
                for (auto j : v1) {
                    string s = words[i];
                    string t = words[j];
                    if (s.size() + 1 != t.size()) continue;
                    int k = 0, p = 0;
                    bool skipped = false;
                    while (k < s.size() && p < t.size()) {
                        if (s[k] == t[p]) {
                            ++k, ++p;
                        } else {
                            if (skipped) break;
                            skipped = true;
                            ++p;
                        }
                    }
                    if (p < t.size() && !skipped) adj[i].push_back(j);
                    if (skipped && k == s.size() && p == t.size())
                        adj[i].push_back(j);
                }
            }
        }

        vector<int> memo(n, -1);
        function<int(int)> dfs = [&](int u) -> int {
            if (memo[u] != -1) return memo[u];
            int result = 0;
            for (int v : adj[u]) {
                result = max(result, dfs(v));
            }
            return memo[u] = result + 1;
        };

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, dfs(i));
        }

        return result;
    }
};
