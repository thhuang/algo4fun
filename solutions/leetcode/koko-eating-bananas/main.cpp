class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l <= r) {
            int m = l + (r - l) / 2;

            long long v = 0;
            for (int p : piles) v += (p - 1) / m + 1;

            if (v <= h) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
