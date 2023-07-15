class Solution {
    vector<char> chars = {'A', 'C', 'G', 'T'};

   public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> valid;
        for (string s : bank) valid.insert(s);

        int steps = 0;
        vector<string> q = {start};
        while (!q.empty()) {
            vector<string> new_q;
            for (string s : q) {
                if (s == end) return steps;

                valid.erase(s);

                for (int i = 0; i < s.size(); ++i) {
                    for (char c : chars) {
                        string new_s = s;
                        new_s[i] = c;
                        if (!valid.count(new_s)) continue;
                        valid.erase(new_s);
                        new_q.emplace_back(new_s);
                    }
                }
            }
            ++steps;
            q = new_q;
        }
        return -1;
    }
};

class Solution {
    bool isConnected(string& s, string& t) {
        int cnt = 0;
        for (int k = 0; k < s.size(); ++k) {
            if (s[k] != t[k]) ++cnt;
            if (cnt > 1) return false;
        }
        return cnt == 1;
    }

   public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();

        int endIndex = -1;
        vector<vector<int>> adj(bank.size() + 1);

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isConnected(bank[i], bank[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }

            if (isConnected(startGene, bank[i])) adj[n].push_back(i);

            if (endIndex == -1 && bank[i] == endGene) endIndex = i;
        }

        queue<pair<int, int>> q;
        q.push({n, 0});
        vector<bool> vis(adj.size(), false);

        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            if (u == endIndex) return d;

            if (vis[u]) continue;
            vis[u] = true;

            for (int v : adj[u]) q.push({v, d + 1});
        }

        return -1;
    }
};
