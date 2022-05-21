class Solution {
   public:
    vector<int> countSmaller(vector<int>& nums) {
        auto [pmin, pmax] = minmax_element(nums.begin(), nums.end());
        int offset = 1 - *pmin;

        int n = nums.size();
        int m = *pmax - *pmin + 1;

        vector<int> tree(m + 1, 0);

        function<int(int)> sum = [&](int k) -> int {
            int s = 0;
            while (k >= 1) {
                s += tree[k];
                k -= k & -k;
            }
            return s;
        };

        function<void(int, int)> add = [&](int k, int x) -> void {
            while (k <= m) {
                tree[k] += x;
                k += k & -k;
            }
        };

        vector<int> result(nums.size());
        for (int i = n - 1; ~i; --i) {
            int k = nums[i] + offset;
            add(k, 1);
            result[i] = sum(k - 1);
        }

        return result;
    }
};
