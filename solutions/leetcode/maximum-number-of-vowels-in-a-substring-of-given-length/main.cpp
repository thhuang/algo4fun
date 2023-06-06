class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

   public:
    int maxVowels(string s, int k) {
        int curr = 0;
        for (int i = 0; i < k - 1; ++i) {
            if (isVowel(s[i])) ++curr;
        }

        int result = curr;
        for (int i = k - 1; i < s.size(); ++i) {
            if (isVowel(s[i])) result = max(result, ++curr);
            if (isVowel(s[i - k + 1])) --curr;
        }

        return result;
    }
};

class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

   public:
    int maxVowels(string s, int k) {
        int result = 0;
        int curr = 0;
        for (int i = 0; i < k - 1; ++i) {
            curr += isVowel(s[i]) ? 1 : 0;
        }
        for (int i = k - 1; i < s.size(); ++i) {
            curr += isVowel(s[i]) ? 1 : 0;
            result = max(result, curr);
            curr -= isVowel(s[i - k + 1]) ? 1 : 0;
        }
        return result;
    }
};
