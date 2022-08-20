class Solution {
   public:
    vector<long long> maximumSegmentSum(vector<int>& nums,
                                        vector<int>& removeQueries) {
        int n = 1;
        while (n <= nums.size()) n *= 2;
        vector<long long> tree(n * 2, 0);

        auto sum = [&](int a, int b) -> long long {
            a += n, b += n;
            long long s = 0;
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

        multiset<long long> seg;
        long long total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            add(i, nums[i]);
            total += nums[i];
        }
        seg.insert(total);

        map<int, long long> idx2seg;
        idx2seg[-1] = *seg.begin();
        idx2seg[nums.size()] = 0;

        vector<long long> result(removeQueries.size());
        for (int i = 0; i < removeQueries.size(); ++i) {
            int k = removeQueries[i];
            add(k, -nums[k]);

            auto it = prev(idx2seg.upper_bound(k));
            seg.erase(seg.find(it->second));

            long long l = sum(it->first + 1, k - 1);
            seg.insert(l);
            idx2seg[it->first] = l;

            long long r = sum(k + 1, next(it)->first - 1);
            seg.insert(r);
            idx2seg[k] = r;

            result[i] = *seg.rbegin();
        }

        return result;
    }
};
