class Solution {
   public:
    bool canPermutePalindrome(string s) {
        array<int, 26> charFreq = {};
        for (char c : s) ++charFreq[c - 'a'];

        bool foundOdd = false;
        for (int v : charFreq) {
            if (v & 1) {
                if (foundOdd) return false;
                foundOdd = true;
            }
        }

        return true;
    }
};
