class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int product = nums.front();
        for (int i = 1; i < n; ++i) {
            result[i] *= product;
            product *= nums[i];
        }

        product = nums.back();
        for (int i = n - 2; ~i; --i) {
            result[i] *= product;
            product *= nums[i];
        }

        return result;
    }
};
