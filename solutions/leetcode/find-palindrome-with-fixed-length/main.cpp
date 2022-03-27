class Solution {
   public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> result;
        int halfLength = (intLength + 1) / 2;
        long long base = pow(10, halfLength - 1);
        for (int q : queries) {
            long long v = base + q - 1;
            if (v >= base * 10) {
                result.push_back(-1);
                continue;
            }

            long long palindrome = 0;
            for (long long pos = intLength & 1 ? 10 : 1; pos <= base;
                 pos *= 10) {
                palindrome = palindrome * 10 + (v / pos) % 10;
            }
            palindrome += v * pow(10, halfLength - (intLength & 1 ? 1 : 0));

            result.push_back(palindrome);
        }

        return result;
    }
};
