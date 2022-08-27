class Solution {
   public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        auto check = [&](int k) -> bool {
            int p = numeric_limits<int>::min();
            auto it = position.begin();
            for (int i = 0; i < m; ++i) {
                while (it != position.end() && *it - k < p) ++it;
                if (it == position.end()) return false;
                p = *it++;
            }
            return true;
        };

        int l = 1, r = position.back() - position.front();
        while (l <= r) {
            int v = l + (r - l) / 2;
            if (check(v)) {
                l = v + 1;
            } else {
                r = v - 1;
            }
        }

        return r;
    }
};
