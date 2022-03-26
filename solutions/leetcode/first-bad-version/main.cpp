// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                r = m;
                continue;
            }
            l = m + 1;
        }
        return r;
    }
};
