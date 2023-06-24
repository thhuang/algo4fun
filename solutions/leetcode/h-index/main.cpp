class Solution {
   public:
    int hIndex(vector<int>& citations) {
        auto check = [&](int h) -> bool {
            int cnt = 0;
            for (int v : citations) cnt += v >= h;
            return cnt >= h;
        };

        int l = 0, r = citations.size();
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r;
    }
};
