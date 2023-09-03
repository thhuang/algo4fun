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

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int result, freq = 0;
        for (int v : nums) {
            if (v == result) {
                ++freq;
            } else {
                if (--freq < 0) {
                    freq = 1;
                    result = v;
                }
            }
        }
        return result;
    }
};
