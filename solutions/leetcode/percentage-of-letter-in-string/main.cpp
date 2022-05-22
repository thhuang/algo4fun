class Solution {
   public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for (char c : s) count += c == letter;
        return count * 100 / s.size();
    }
};
