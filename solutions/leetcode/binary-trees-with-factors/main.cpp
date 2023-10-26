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

class Solution {
    const int mod = 1e9 + 7;
    typedef long long ll;

   public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int result = 0;
        unordered_map<int, int> memo;

        for (int v : arr) {
            ll cnt = 1;
            for (auto [a, aCnt] : memo) {
                if (v % a != 0) continue;
                int b = v / a;
                if (memo.count(b) == 0) continue;
                ll bCnt = memo[b];
                (cnt += aCnt * bCnt % mod) %= mod;
            }
            memo[v] = cnt;
            (result += cnt) %= mod;
        }

        return result;
    }
};
