class Solution {
   public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = *max_element(candies.begin(), candies.end());

        auto count = [&](int p) -> long long {
            if (p == 0) return numeric_limits<long long>::max();

            long long sum = 0;
            for (long long c : candies) sum += c / p;
            return sum;
        };

        while (l <= r) {
            int m = l + (r - l) / 2;
            long long c = count(m);
            if (c < k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l - 1;
    }
};
