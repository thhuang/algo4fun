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
