class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        function<bool(int)> isValid = [&](int cap) -> bool {
            int d = 1;
            int curr = 0;
            for (int w : weights) {
                curr += w;
                if (curr <= cap) continue;
                curr = w;
                ++d;
            }
            return d <= days;
        };

        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isValid(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
