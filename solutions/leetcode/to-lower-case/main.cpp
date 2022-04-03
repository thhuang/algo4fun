class Solution {
   public:
    string toLowerCase(string s) {
        for (char& c : s)
            if (c >= 'A' && c - 'A' < 26) c |= 1 << 5;
        return s;
    }
};
