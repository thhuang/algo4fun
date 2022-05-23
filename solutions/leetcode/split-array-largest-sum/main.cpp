class Solution {
   public:
    int splitArray(vector<int>& nums, int m) {
        int left = numeric_limits<int>::min();
        int right = 0;
        for (int v : nums) {
            right += v;
            left = max(left, v);
        }

        auto count = [&nums](int sum) -> int {
            int c = 1;
            for (int i = 0, s = 0; i < nums.size(); ++i) {
                s += nums[i];
                if (s > sum) {
                    ++c;
                    s = nums[i];
                }
            }
            return c;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int c = count(mid);
            if (c <= m) {
                right = mid - 1;
            } else {  // c > m
                left = mid + 1;
            }
        }

        return left;
    }
};
