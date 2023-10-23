class Solution {
   public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = -1, r = n;
        while (r - l > 1) {  // (l, r]
            int m = l + (r - l) / 2;
            int h = n - m;
            if (citations[m] >= h) {
                r = m;
            } else {
                l = m;
            }
        }
        return n - r;
    }
};
