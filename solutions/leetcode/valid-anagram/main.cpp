class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (size(s) != size(t)) return false;

        array<int, 26> chars;
        fill(begin(chars), end(chars), 0);

        for (char c : s) ++chars[c - 'a'];
        for (char c : t) {
            if (--chars[c - 'a'] < 0) return false;
        }

        return true;
    }
};

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (size(s) != size(t)) return false;
        unordered_map<char, int> count;
        for (auto c : s) ++count[c];
        for (auto c : t) {
            if (--count[c] < 0) return false;
        }
        return true;
    }
};
