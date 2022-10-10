class Solution {
   public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();

        if (n < 2) return "";

        for (int i = 0; i < n / 2; ++i) {
            if (palindrome[i] == 'a') continue;
            return palindrome.substr(0, i) + "a" + palindrome.substr(i + 1);
        }

        palindrome.pop_back();
        return palindrome + "b";
    }
};
