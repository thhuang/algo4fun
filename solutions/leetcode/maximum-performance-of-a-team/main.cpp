class Solution {
    typedef unsigned long long ull;

   public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                       int k) {
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&efficiency](int a, int b) -> bool {
            return efficiency[a] > efficiency[b];
        });

        auto cmp = [&speed](int a, int b) -> bool {
            return speed[a] > speed[b];
        };

        ull result = 0;
        ull sum_sp = 0;
        priority_queue<int, vector<int>, decltype(cmp)> mn_sp_idx(cmp);

        for (int i = 0; i < n; ++i) {
            sum_sp += speed[idx[i]];
            mn_sp_idx.push(idx[i]);

            if (mn_sp_idx.size() > k) {
                sum_sp -= speed[mn_sp_idx.top()];
                mn_sp_idx.pop();
            }

            result = max(result, sum_sp * efficiency[idx[i]]);
        }

        return result % ((ull)1e9 + 7);
    }
};
