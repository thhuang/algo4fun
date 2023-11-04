class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = 0;
        int sum = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum >= target) {
                int length = r - l + 1;
                result = result == 0 ? length : min(result, length);
                sum -= nums[l++];
            }
        }
        return result;
    }
};

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = nums.size() + 1;
        for (int l = 0, r = 0, curr = 0; r < nums.size(); ++r) {
            curr += nums[r];
            while (curr >= target) {
                result = min(result, r - l + 1);
                curr -= nums[l++];
            }
        }
        return result % (nums.size() + 1);
    }
};

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int result = n + 1;
        for (int l = 0, r = 0, sum = 0; r < n; ++r) {
            sum += nums[r];
            while (sum >= target) {
                result = min(result, r - l + 1);
                sum -= nums[l++];
            }
        }
        if (result > n) return 0;
        return result;
    }
};
