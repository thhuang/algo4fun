class Solution {
    const int mod = 1e9 + 7;

   public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) power.push_back(i);
        }

        vector<int> prefix(power.size() + 1, 0);
        for (int i = 1, s = 0; i <= power.size(); ++i) {
            prefix[i] = s += power[i - 1];
        }

        vector<int> result;
        for (auto q : queries) {
            int l = q[0], r = q[1];
            int p = prefix[r + 1] - prefix[l];

            long long v = 1;
            while (p >= 32) {
                v <<= 32;
                v %= mod;
                p -= 32;
            }
            v <<= p;
            v %= mod;

            result.push_back(v % mod);
        }

        return result;
    }
};

class Solution {
    const int mod = 1e9 + 7;

   public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        for (int x = n; x; x &= x - 1) power.push_back(x & ~(x - 1));

        vector<int> result;
        for (auto q : queries) {
            int l = q[0], r = q[1];
            long v = 1;
            for (int i = l; i <= r; ++i) v = v * power[i] % mod;
            result.push_back(v);
        }

        return result;
    }
};
