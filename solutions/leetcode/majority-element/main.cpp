class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int result = nums.front();
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == result) {
                ++count;
                continue;
            }
            if (--count == 0) {
                result = nums[i];
                count = 1;
            }
        }
        return result;
    }
};
