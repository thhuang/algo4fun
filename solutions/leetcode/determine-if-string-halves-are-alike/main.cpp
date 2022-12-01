class Solution {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                  'A', 'E', 'I', 'O', 'U'};

   public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int v = 0;
        for (int i = 0; i < n / 2; ++i) {
            v += vowels.count(s[i]);
        }
        for (int i = n / 2; i < n; ++i) {
            v -= vowels.count(s[i]);
        }
        return v == 0;
    }
};
