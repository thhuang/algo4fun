class Solution {
   public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        auto check = [&](int v) -> bool {
            double t = 0;
            for (int i = 0; i < dist.size() - 1; ++i) {
                t += (dist[i] + v - 1) / v;
            }
            t += (double)dist.back() / v;
            return t <= hour;
        };

        int mx = *max_element(dist.begin(), dist.end()) * 100;
        int l = 1, r = mx;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l <= mx ? l : -1;
    }
};
