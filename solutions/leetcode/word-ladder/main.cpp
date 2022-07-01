class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = beginWord.size();

        unordered_set<string> valid;
        for (string s : wordList) valid.insert(s);

        if (valid.count(endWord) == 0) return 0;

        int steps = 1;
        vector<string> q = {beginWord};
        while (!q.empty()) {
            vector<string> new_q;
            for (string u : q) {
                if (u == endWord) return steps;

                for (int i = 0; i < n; ++i) {
                    string v = u;
                    for (int j = 0; j < 26; ++j) {
                        char c = 'a' + j;
                        v[i] = c;
                        if (valid.count(v)) new_q.push_back(v);
                        valid.erase(v);
                    }
                }
            }

            ++steps;
            q = new_q;
        }

        return 0;
    }
};

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> valid;
        for (const string& s : wordList) valid.insert(s);

        if (valid.count(endWord) == 0) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [s, d] = q.front();
            q.pop();

            if (s == endWord) return d;

            for (int i = 0; i < s.size(); ++i) {
                char u = s[i];
                for (char v = 'a'; v <= 'z'; ++v) {
                    if (v == u) continue;
                    s[i] = v;
                    if (valid.count(s) == 0) continue;
                    q.push({s, d + 1});
                    valid.erase(s);
                }
                s[i] = u;
            }
        }

        return 0;
    }
};
