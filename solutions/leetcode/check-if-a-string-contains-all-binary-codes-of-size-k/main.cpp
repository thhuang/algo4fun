class Solution {
   public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        unordered_set<int> us;
        unsigned v = 0;
        for (int i = 0; i < k - 1; ++i) v = (v << 1) + (s[i] == '1');
        for (int i = k - 1; i < s.size(); ++i) {
            v = (v << 1) + (s[i] == '1');
            us.insert(v);
            v -= (s[i - k + 1] == '1') << (k - 1);
        }

        return us.size() == (1 << k);
    }
};

class Solution {
   public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;

        vector<bool> vis(1 << k, false);

        int v = 0;
        for (int i = 0; i < k - 1; ++i) {
            v = (v << 1) + (s[i] == '1');
        }

        for (int i = k - 1; i < s.size(); ++i) {
            v = (v << 1) + (s[i] == '1');
            vis[v] = true;
            v -= (s[i - k + 1] == '1') << (k - 1);
        }

        return find(vis.begin(), vis.end(), false) == vis.end();
    }
};
