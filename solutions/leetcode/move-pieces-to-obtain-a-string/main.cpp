class Solution {
   public:
    bool canChange(string start, string target) {
        int n = start.size();

        string s, t;
        int sl = 0, tl = 0;
        for (int i = 0; i < n; ++i) {
            if (target[i] == 'L') ++tl;
            if (start[i] == 'L') {
                ++sl;
                if (sl > tl) return false;
            }
            if (start[i] != '_') s += start[i];
            if (target[i] != '_') t += target[i];
        }
        if (sl != tl || s != t) return false;

        int sr = 0, tr = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (target[i] == 'R') ++tr;
            if (start[i] == 'R') {
                ++sr;
                if (sr > tr) return false;
            }
        }
        return sr == tr;
    }
};
