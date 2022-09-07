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
