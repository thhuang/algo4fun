class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check = [&](int m) -> bool {
            long long sum = 0;
            for (int v : piles) sum += (v - 1) / m + 1;
            return sum <= h;
        };

        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
