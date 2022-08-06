class Solution {
   public:
    int minMovesToMakePalindrome(string s) {
        int result = 0;
        while (s.size()) {
            int i = s.find(s.back());
            if (i == s.size() - 1) {
                result += i / 2;
            } else {
                result += i;
                s.erase(s.begin() + i);
            }
            s.pop_back();
        }
        return result;
    }
};
