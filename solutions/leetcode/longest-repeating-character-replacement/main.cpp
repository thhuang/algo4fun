class Solution {
   public:
    int characterReplacement(string s, int k) {
        int result = 0;
        for (char c = 'A'; c <= 'Z'; ++c) {
            int diff = 0;
            for (int l = 0, r = 0; r < s.size(); ++r) {
                if (s[r] != c) ++diff;
                while (diff > k) {
                    if (s[l++] != c) --diff;
                }
                result = max(result, r - l + 1);
            }
        }
        return result;
    }
};

class Solution {
   public:
    int characterReplacement(string s, int k) {
        array<int, 26> count;
        count.fill(0);
        int max_count = 0;
        int result = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            max_count = max(max_count, ++count[s[r] - 'A']);
            while (r - l + 1 - max_count > k) --count[s[l++] - 'A'];
            result = max(result, r - l + 1);
        }
        return result;
    }
};
