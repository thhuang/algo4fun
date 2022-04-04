class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int nil = 5000;
        int n = size(nums);
        vector<vector<int>> dp(n, vector<int>(n, nil));
        for (int i = 0; i + 1 < n; ++i) dp[i][i + 1] = nums[i + 1] - nums[i];

        int count = 0;
        for (int d = 2; d < n; ++d) {
            for (int i = 0; i + d < n; ++i) {
                int diff = nums[i + d] - nums[i + d - 1];
                if (diff != dp[i][i + d - 1]) continue;
                dp[i][i + d] = diff;
                if (d >= 2) ++count;
            }
        }

        return count;
    }
};

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = size(nums);

        int count = 0;
        for (int l = 0; l + 2 < n; ++l) {
            for (int r = l + 2; r < n; ++r) {
                if (nums[r] - nums[r - 1] != nums[r - 1] - nums[r - 2]) break;
                ++count;
            }
        }

        return count;
    }
};

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int d = 0;
        for (int i = 2; i < size(nums); ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                ++d;
                continue;
            }
            ans += d * (d + 1) / 2;
            d = 0;
        }
        return ans += d * (d + 1) / 2;
    }
};
