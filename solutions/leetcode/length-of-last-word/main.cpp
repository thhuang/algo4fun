class Solution {
   public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') --i;
        int result = 0;
        while (i >= 0 && s[i] != ' ') --i, ++result;
        return result;
    }
};

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int n = s.size();
        for (int l = 0, r; l < n; l = r) {
            r = l + 1;
            if (s[l] == ' ') continue;
            while (r < n && s[r] != ' ') ++r;
            result = r - l;
        }
        return result;
    }
};
