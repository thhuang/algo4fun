class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> valid(wordList.begin(), wordList.end());
        valid.erase(beginWord);

        if (valid.count(endWord) == 0) return 0;

        queue<tuple<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [u, s] = q.front();
            q.pop();

            if (u == endWord) return s;

            ++s;
            for (int i = 0; i < u.size(); ++i) {
                char o = u[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == o) continue;
                    u[i] = c;
                    if (valid.count(u) == 0) continue;
                    valid.erase(u);
                    q.push({u, s});
                }
                u[i] = o;
            }
        }

        return 0;
    }
};

class Solution {
    bool isConnected(string& s, string& t) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) ++cnt;
            if (cnt > 1) return false;
        }
        return cnt == 1;
    }

   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = wordList.size();

        int endIndex = -1;
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isConnected(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            if (endIndex == -1 && endWord == wordList[i]) endIndex = i;
            if (isConnected(beginWord, wordList[i])) adj[n].push_back(i);
        }

        if (endIndex == -1) return 0;

        queue<pair<int, int>> q;
        q.push({n, 1});

        vector<bool> vis(n + 1, false);
        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            if (u == endIndex) return d;
            if (vis[u]) continue;
            vis[u] = true;

            for (int v : adj[u]) q.push({v, d + 1});
        }

        return 0;
    }
};
