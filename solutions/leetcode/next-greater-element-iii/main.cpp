class Solution {
   public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int m = s.size();

        int l = m - 2;
        while (l >= 0 && s[l] >= s[l + 1]) --l;

        if (l == -1) return -1;

        int r = m - 1;
        while (s[r] <= s[l]) --r;

        swap(s[l], s[r]);
        sort(s.begin() + l + 1, s.end());

        long long v = stoll(s);

        return v <= numeric_limits<int>::max() ? v : -1;
    }
};
