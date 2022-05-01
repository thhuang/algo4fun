class Solution {
   public:
    vector<int> findPermutation(string s) {
        vector<int> result(s.size() + 1);
        iota(result.begin(), result.end(), 1);

        for (int l = 0; l < s.size(); ++l) {
            int r = l;
            while (s[r] == 'D') ++r;
            if (l == r) continue;

            reverse(result.begin() + l, result.begin() + r + 1);
            l = r;
        }

        return result;
    }
};
