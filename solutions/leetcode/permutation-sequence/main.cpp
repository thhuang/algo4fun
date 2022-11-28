class Solution {
   public:
    string getPermutation(int n, int k) {
        string s(n, ' ');
        iota(s.begin(), s.end(), '1');

        for (int i = 1; i < k; ++i) {
            int l = n - 2;
            while (s[l] >= s[l + 1]) --l;
            int j = n - 1;
            while (s[j] < s[l]) --j;
            swap(s[l], s[j]);
            sort(s.begin() + l + 1, s.end());
        }

        return s;
    }
};
