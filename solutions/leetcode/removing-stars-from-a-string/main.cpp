class Solution {
   public:
    string removeStars(string s) {
        string result;
        for (char c : s) {
            if (c != '*') {
                result += c;
            } else if (!result.empty()) {
                result.pop_back();
            }
        }
        return result;
    }
};
