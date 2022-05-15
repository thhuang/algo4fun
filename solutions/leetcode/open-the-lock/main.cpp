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

class Solution {
    const string start = "0000";
    const array<int, 2> directions = {1, 9};

   public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> vis;
        for (string s : deadends) vis[s] = -1;

        if (vis.count(start) || vis.count(target)) return -1;

        deque<string> q = {start};
        while (!q.empty()) {
            string s = q.front();
            q.pop_front();

            int turns = vis[s];
            if (s == target) return turns;

            for (int i = 0; i < s.size(); ++i) {
                char c = s[i];

                for (int d : directions) {
                    s[i] = '0' + (c - '0' + d) % 10;
                    if (vis.count(s)) continue;
                    vis[s] = turns + 1;
                    q.push_back(s);
                }

                s[i] = c;
            }
        }

        return -1;
    }
};
