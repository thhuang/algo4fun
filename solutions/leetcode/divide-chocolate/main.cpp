class Solution {
   public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        auto check = [&](int target) -> bool {
            int require = k + 1;
            int sum = 0;
            for (int s : sweetness) {
                if ((sum += s) >= target) {
                    --require;
                    sum = 0;
                }
                if (require == 0) return true;
            }
            return false;
        };

        int l = 0, r = 0;
        for (int s : sweetness) r += s;
        r /= (k + 1);

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
