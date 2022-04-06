class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> invalid;
        for (string s : deadends) invalid.insert(s);

        deque<string> q = {"0000"};
        int steps = 0;
        while (!q.empty()) {
            deque<string> new_q;
            for (string u : q) {
                if (u == target) return steps;
                if (invalid.count(u)) continue;

                invalid.insert(u);

                for (int i = 0; i < 4; ++i) {
                    string v = u;
                    int digit = v[i] - '0';

                    v[i] = '0' + (digit + 1) % 10;
                    new_q.push_back(v);

                    v[i] = '0' + (digit + 9) % 10;
                    new_q.push_back(v);
                }
            }
            ++steps;
            q = new_q;
        }

        return -1;
    }
};
