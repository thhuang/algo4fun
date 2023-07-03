class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sz = words.front().size();
        int n = sz * words.size();

        unordered_map<string, int> want;
        for (const string& w : words) ++want[w];

        function<bool(int)> check = [&](int i) -> bool {
            auto got = want;
            for (int j = 0; j < words.size(); ++j) {
                string w = s.substr(i + j * sz, sz);
                if (--got[w] < 0) return false;
            }
            return true;
        };

        vector<int> result;
        for (int i = 0; i + n <= s.size(); ++i) {
            if (check(i)) result.push_back(i);
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words[0].size();
        int n = words.size();

        unordered_map<string, int> valid;
        for (string& w : words) ++valid[w];

        vector<int> result;
        for (int i = 0; i < m; ++i) {
            unordered_map<string, int> seen;
            for (int l = i, r = i; r + m <= s.size(); r += m) {
                string w = s.substr(r, m);

                if (valid.count(w) == 0) {
                    seen.clear();
                    l = r + m;
                    continue;
                }

                while (seen[w] >= valid[w]) {
                    --seen[s.substr(l, m)];
                    l += m;
                }
                ++seen[w];

                if ((r - l) / m + 1 == n) result.push_back(l);
            }
        }

        return result;
    }
};
