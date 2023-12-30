class Solution {
   public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        array<int, 26> charFreq = {};
        for (const string& w : words) {
            for (const char& c : w) {
                ++charFreq[c - 'a'];
            }
        }

        for (int v : charFreq) {
            if (v % n != 0) {
                return false;
            }
        }

        return true;
    }
};
