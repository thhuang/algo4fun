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

class Solution {
   public:
    vector<int> countSmaller(vector<int>& nums) {
        auto p = minmax_element(nums.begin(), nums.end());
        int mn = *p.first, mx = *p.second;

        int n = 1;
        while (n < mx - mn + 1) n *= 2;
        vector<int> tree(n * 2, 0);

        auto sum = [&](int a, int b) -> int {
            a += n, b += n;
            int s = 0;
            while (a <= b) {
                if (a % 2 == 1) s += tree[a++];
                if (b % 2 == 0) s += tree[b--];
                a /= 2, b /= 2;
            }
            return s;
        };

        auto add = [&](int k, int x) -> void {
            k += n;
            tree[k] += x;
            for (k /= 2; k >= 1; k /= 2) {
                tree[k] = tree[k * 2] + tree[k * 2 + 1];
            }
        };

        vector<int> result(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int k = nums[i] - mn;
            add(k, 1);
            result[i] = sum(0, k - 1);
        }

        return result;
    }
};
