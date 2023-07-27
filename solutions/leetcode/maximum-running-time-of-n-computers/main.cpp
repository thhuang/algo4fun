class Solution {
    typedef long long ll;

   public:
    long long maxRunTime(int n, vector<int>& batteries) {
        auto check = [&](ll t) -> bool {
            ll power = 0;
            for (ll v : batteries) power += min(v, t);
            return power >= t * n;
        };

        ll l = 0;
        ll r = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r;
    }
};
