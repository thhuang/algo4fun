class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) swap(nums[i], nums[n++]);
        }

        for (int i = 0; i < n; ++i) {
            while (nums[i] - 1 != i && nums[i] > 0 && nums[i] - 1 < n &&
                   nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (0 <= nums[i] && nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) return i;
        }
        return n;
    }
};
