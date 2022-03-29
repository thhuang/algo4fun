class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int max_dist = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > max_dist) return false;
            max_dist = max(max_dist, i + nums[i]);
            if (max_dist >= nums.size() - 1) return true;
        }
        return false;
    }
};
