class Solution {
   public:
    int strStr(string haystack, string needle) {
        vector<int> prefix(needle.size(), 0);
        for (int i = 1; i < needle.size(); ++i) {
            int d = prefix[i - 1];
            while (d > 0 && needle[i] != needle[d]) d = prefix[d - 1];
            if (needle[i] == needle[d]) ++d;
            prefix[i] = d;
        }

        for (int i = 0, j = 0; i < haystack.size();) {
            if (haystack[i] == needle[j]) {
                ++i, ++j;
                if (j == needle.size()) return i - needle.size();
            } else {
                if (j == 0) {
                    ++i;
                } else {
                    j = prefix[j - 1];
                }
            }
        }

        return -1;
    }
};
