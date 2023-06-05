class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0, v = 1; i < n; ++i) {
            result[i] = v;
            v *= nums[i];
        }
        for (int i = n - 1, v = 1; i >= 0; --i) {
            result[i] *= v;
            v *= nums[i];
        }
        return result;
    }
};
