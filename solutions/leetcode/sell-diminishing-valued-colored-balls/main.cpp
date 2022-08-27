class Solution {
    const int mod = 1e9 + 7;

   public:
    int maxProfit(vector<int>& inventory, int orders) {
        unordered_map<int, int> cnt;
        for (int v : inventory) ++cnt[v];

        vector<pair<int, int>> balls(cnt.begin(), cnt.end());
        balls.push_back({0, 0});
        sort(balls.begin(), balls.end());

        long long result = 0;
        while (orders) {
            int n = balls.size();
            auto [r, c] = balls[n - 1];
            int l = balls[n - 2].first;

            if (orders >= 1LL * (r - l) * c) {
                orders -= 1LL * (r - l) * c;
                result += 1LL * (r + l + 1) * (r - l) * c / 2 % mod;
                result %= mod;

                balls.pop_back();
                balls.back().second += c;

                continue;
            }

            int v = orders / c;
            result += 1LL * (r + r - v + 1) * v * c / 2 % mod;
            result += 1LL * (r - v) * (orders % c) % mod;
            result %= mod;

            break;
        }

        return result;
    }
};
