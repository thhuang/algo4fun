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

        int i = 0;  // haystack
        int j = 0;  // needle
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                ++i, ++j;
                if (j == needle.size()) return i - needle.size();
                continue;
            }
            j != 0 ? j = prefix[j - 1] : ++i;
        }

        return -1;
    }
};
