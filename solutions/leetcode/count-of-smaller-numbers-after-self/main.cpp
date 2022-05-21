class Solution {
   public:
    vector<int> countSmaller(vector<int>& nums) {
        auto minmax_its = minmax_element(nums.begin(), nums.end());
        int mn = *minmax_its.first;
        int mx = *minmax_its.second;
        int n = mx - mn + 1;
        int offset = -mn + 1;
        vector<int> tree(n + 1, 0);

        function<int(int)> sum = [&](int k) -> int {
            int s = 0;
            while (k >= 1) {
                s += tree[k];
                k -= k & -k;
            }
            return s;
        };

        function<void(int, int)> add = [&](int k, int x) -> void {
            while (k <= n) {
                tree[k] += x;
                k += k & -k;
            }
        };

        vector<int> result(nums.size());
        int i = nums.size() - 1;
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            int k = *it + offset;
            add(k, 1);
            result[i--] = sum(k - 1);
        }

        return result;
    }
};
