class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums.front();

        int sum = 0;
        int ans1 = numeric_limits<int>::min();
        int curr = numeric_limits<int>::min();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            curr = max(curr, 0) + nums[i];
            ans1 = max(ans1, curr);
        }

        int ans2 = numeric_limits<int>::max();
        curr = numeric_limits<int>::max();
        for (int i = 1; i < n; ++i) {
            curr = min(curr, 0) + nums[i];
            ans2 = min(ans2, curr);
        }
        ans2 = sum - ans2;

        int ans3 = numeric_limits<int>::max();
        curr = numeric_limits<int>::max();
        for (int i = 0; i < n - 1; ++i) {
            curr = min(curr, 0) + nums[i];
            ans3 = min(ans3, curr);
        }
        ans3 = sum - ans3;

        return max({ans1, ans2, ans3});
    }
};

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int all_sum = 0;

        int max_sum = numeric_limits<int>::min();
        for (int i = 0, curr = numeric_limits<int>::min(); i < nums.size();
             ++i) {
            all_sum += nums[i];
            curr = max(0, curr) + nums[i];
            max_sum = max(max_sum, curr);
        }

        int min_sum = numeric_limits<int>::max();
        for (int i = 0, curr = numeric_limits<int>::max(); i < nums.size();
             ++i) {
            curr = min(0, curr) + nums[i];
            min_sum = min(min_sum, curr);
        }

        if (min_sum == all_sum) return max_sum;
        return max(max_sum, all_sum - min_sum);
    }
};
