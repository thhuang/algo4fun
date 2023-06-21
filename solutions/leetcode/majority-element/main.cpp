class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == result) {
                ++cnt;
            } else {
                if (--cnt == -1) cnt = 1, result = nums[i];
            }
        }
        return result;
    }
};
