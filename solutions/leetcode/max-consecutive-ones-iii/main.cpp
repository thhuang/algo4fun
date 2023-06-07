class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) --k;
            while (k < 0 && nums[r] == 0) {
                if (nums[l++] == 0) ++k;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) --k;
            if (k < 0) {
                while (nums[l++] == 1);
                ++k;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
