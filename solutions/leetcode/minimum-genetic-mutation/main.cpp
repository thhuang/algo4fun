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
