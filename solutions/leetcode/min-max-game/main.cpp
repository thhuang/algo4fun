class Solution {
   public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> new_nums(nums.size() / 2);
            for (int i = 0; i < nums.size() / 2; ++i) {
                if (i % 2 == 0) {
                    new_nums[i] = min(nums[i * 2], nums[i * 2 + 1]);
                } else {
                    new_nums[i] = max(nums[i * 2], nums[i * 2 + 1]);
                }
            }
            nums = move(new_nums);
        }
        return nums.back();
    }
};

class Solution {
   public:
    int minMaxGame(vector<int>& nums) {
        for (int k = nums.size(); k > 1; k >>= 1) {
            for (int i = 0; i < nums.size() / 2; ++i) {
                if (i % 2 == 0) {
                    nums[i] = min(nums[i * 2], nums[i * 2 + 1]);
                } else {
                    nums[i] = max(nums[i * 2], nums[i * 2 + 1]);
                }
            }
        }
        return nums.front();
    }
};
