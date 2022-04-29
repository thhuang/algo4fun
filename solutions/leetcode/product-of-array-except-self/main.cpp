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

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size());
        for (int i = nums.size() - 1, p = 1; ~i; --i) {
            products[i] = p *= nums[i];
        }

        vector<int> result(nums.size());
        for (int i = 0, p = 1; i < nums.size(); ++i) {
            result[i] = p;
            if (i + 1 < nums.size()) result[i] *= products[i + 1];
            p *= nums[i];
        }

        return result;
    }
};
