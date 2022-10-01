class Solution {
   public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        // nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
        // nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff

        vector<int> nums(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) nums[i] = nums1[i] - nums2[i];

        // nums[i] - diff <= nums[j]

        int mn = *min_element(nums.begin(), nums.end());
        mn = min(mn, mn - diff);

        int mx = *max_element(nums.begin(), nums.end());
        mx = max(mx, mx - diff);

        int offset = -mn;
        int len = mx - mn + 1;

        int n = 1;
        while (n <= len) n *= 2;
        vector<int> tree(n * 2, 0);

        auto add = [&](int k, int x) -> void {
            k += n;
            tree[k] += x;
            for (k /= 2; k > 0; k /= 2) {
                tree[k] = tree[k * 2] + tree[k * 2 + 1];
            }
        };

        auto sum = [&](int l, int r) -> int {
            l += n;
            r += n;
            int s = 0;
            while (l <= r) {
                if (l % 2 == 1) s += tree[l++];
                if (r % 2 == 0) s += tree[r--];
                l /= 2, r /= 2;
            }
            return s;
        };

        long long result = 0;
        for (int v : nums) {
            int j = v + offset;
            result += sum(0, j);
            add(j - diff, 1);
        }

        return result;
    }
};
