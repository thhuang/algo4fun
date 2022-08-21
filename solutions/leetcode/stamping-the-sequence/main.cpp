class Solution {
    bool match(const string& a, const string& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) continue;
            if (a[i] == '?' || b[i] == '?') continue;
            return false;
        }
        return true;
    }

    void removeStamp(string& s, int l, int r) {
        for (int i = l; i < r; ++i) s[i] = '?';
    }

   public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size();
        int n = target.size();

        string initial = string(n, '?');
        string removed = string(m, '?');

        vector<int> rresult;
        while (target != initial) {
            string new_target = target;
            for (int i = 0; i < n - m + 1; ++i) {
                string s = new_target.substr(i, m);
                if (s == removed) continue;
                if (!match(s, stamp)) continue;
                removeStamp(new_target, i, i + m);
                rresult.push_back(i);
            }
            if (new_target == target) return {};
            target = move(new_target);
        }

        return {rresult.rbegin(), rresult.rend()};
    }
};
