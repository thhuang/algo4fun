class Solution {
    const int mod = 1e9 + 7;

   public:
    int numberWays(vector<vector<int>>& hats) {
        int m = 40;
        int n = hats.size();

        vector<unordered_set<int>> preference(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < hats[i].size(); ++j) {
                preference[i].emplace(hats[i][j] - 1);
            }
        }

        vector<vector<int>> cache(m, vector<int>(1 << n, -1));
        function<int(int, int, int)> search = [&](int i, int assigned,
                                                  int count) -> int {
            if (count == n) return 1;
            if (m - i < n - count) return 0;
            if (cache[i][assigned] != -1) return cache[i][assigned];

            long long result = search(i + 1, assigned, count);
            for (int j = 0, mask = 1; j < n; ++j, mask <<= 1) {
                if (assigned & mask) continue;
                if (preference[j].count(i) == 0) continue;
                result =
                    (result + search(i + 1, assigned | mask, count + 1)) % mod;
            }

            return cache[i][assigned] = result;
        };

        return search(0, 0, 0);
    }
};
