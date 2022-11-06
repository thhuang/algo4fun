class Solution {
   public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        int n = s.size();

        string ss = s + s;
        string_view sv(ss);

        string_view result = sv.substr(0, n);
        for (int i = 1; i < n; ++i) {
            result = min(result, sv.substr(i, n));
        }

        return string{result};
    }
};
