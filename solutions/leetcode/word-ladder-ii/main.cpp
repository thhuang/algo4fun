class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> valid(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> adj;

        queue<string> q;
        q.push(beginWord);
        if (valid.count(beginWord)) valid.erase(valid.find(beginWord));

        while (!q.empty()) {
            unordered_set<string> enqueued;

            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string u = q.front();
                q.pop();

                for (int i = 0; i < u.size(); ++i) {
                    string v = u;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        v[i] = c;
                        if (valid.count(v)) {
                            adj[v].push_back(u);

                            if (enqueued.count(v) == 0) {
                                enqueued.insert(v);
                                q.push(v);
                            }
                        }
                    }
                }
            }

            for (const string& v : enqueued) {
                valid.erase(v);
            }
        }

        vector<vector<string>> result;
        vector<string> curr = {endWord};
        function<void()> dfs = [&]() -> void {
            const string& u = curr.back();

            if (u == beginWord) {
                result.emplace_back(curr.rbegin(), curr.rend());
                return;
            }

            if (!result.empty() && curr.size() > result.front().size()) return;

            for (const string& v : adj[u]) {
                curr.push_back(v);
                dfs();
                curr.pop_back();
            }
        };

        dfs();

        return result;
    }
};
