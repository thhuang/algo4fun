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
