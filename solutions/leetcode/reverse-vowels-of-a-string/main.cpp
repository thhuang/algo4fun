class Solution {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                  'A', 'E', 'I', 'O', 'U'};

   public:
    string reverseVowels(string s) {
        for (int l = 0, r = s.size() - 1; l < r;) {
            if (vowels.count(s[l]) == 0) {
                ++l;
            } else if (vowels.count(s[r]) == 0) {
                --r;
            } else {
                swap(s[l++], s[r--]);
            }
        }
        return s;
    }
};

class Solution {
    const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                        'A', 'E', 'I', 'O', 'U'};

   public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && vowels.count(s[l]) == 0) ++l;
            while (l < r && vowels.count(s[r]) == 0) --r;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
