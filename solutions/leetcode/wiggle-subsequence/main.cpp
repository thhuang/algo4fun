class Solution {
    struct DP {
        int pos, neg;
    };

   public:
    int wiggleMaxLength(vector<int>& nums) {
        DP dp = {1, 1};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                dp.pos = dp.neg + 1;
            } else if (nums[i - 1] < nums[i]) {
                dp.neg = dp.pos + 1;
            }
        }
        return max(dp.pos, dp.neg);
    }
};

class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        auto process = [&](bool pos) -> int {
            int c = 1;
            for (int i = 1, v = nums.front(); i < nums.size(); ++i) {
                if ((pos && nums[i] > v) || (!pos && nums[i] < v)) {
                    pos = !pos;
                    ++c;
                }
                v = nums[i];
            }
            return c;
        };
        return max(process(true), process(false));
    }
};
