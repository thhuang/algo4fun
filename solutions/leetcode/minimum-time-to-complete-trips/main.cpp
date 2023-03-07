class Solution {
    using ll = long long;

   public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto isValid = [&](ll v) -> bool {
            ll trips = 0;
            for (auto t : time) trips += v / t;
            return trips >= totalTrips;
        };

        ll l = 0;
        ll r = (ll)totalTrips * *max_element(time.begin(), time.end());

        while (l <= r) {
            ll m = l + (r - l) / 2;
            if (isValid(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
