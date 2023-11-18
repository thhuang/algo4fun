class Solution {
   public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers,
                            int target, int full, int partial) {
        int n = flowers.size();

        sort(flowers.begin(), flowers.end());

        if (flowers[0] >= target) {
            return (long long)n * full;
        }

        int leftBoundary = -1;
        vector<long long> fillToMin(n, 0);
        for (int i = 1; i < n; ++i) {
            fillToMin[i] =
                (long long)i * (flowers[i] - flowers[i - 1]) + fillToMin[i - 1];
        }

        vector<long long> fillToTarget(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            fillToTarget[i] =
                (long long)max(0, target - flowers[i]) + fillToTarget[i + 1];
        }

        long long result = 0;
        for (int r = n; r >= 0; --r) {
            long long beauty = (long long)(n - r) * full;

            long long remain = newFlowers - fillToTarget[r];
            if (remain < 0) break;

            int l = upper_bound(fillToMin.begin(), fillToMin.end(), remain) -
                    fillToMin.begin() - 1;
            l = min(l, r - 1);
            if (l < 0) {
                result = max(result, beauty);
                continue;
            }

            long long mn = flowers[l] + (remain - fillToMin[l]) / (l + 1);
            mn = min(mn, (long long)target - 1);

            beauty += mn * partial;

            result = max(result, beauty);
        }

        return result;
    }
};
