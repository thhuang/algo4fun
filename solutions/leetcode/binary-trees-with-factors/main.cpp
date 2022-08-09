class Solution {
    const int mod = 1e9 + 7;

   public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, long long> dp;
        for (int v : arr) dp[v] = 1;

        for (auto i = dp.begin(); i != dp.end(); ++i) {
            for (auto j = dp.begin(); j != i; ++j) {
                if (i->first % j->first != 0) continue;
                auto k = dp.find(i->first / j->first);
                if (k == dp.end()) continue;
                i->second = (i->second + (j->second * k->second % mod)) % mod;
            }
        }

        long long result = 0;
        for (auto it = dp.begin(); it != dp.end(); ++it) {
            result = (result + it->second) % mod;
        }

        return result;
    }
};
