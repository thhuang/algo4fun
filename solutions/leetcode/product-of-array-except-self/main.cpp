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

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n + 1, 1);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        vector<int> result;
        for (int i = 0, v = 1; i < n; ++i) {
            result.push_back(v * suffix[i + 1]);
            v *= nums[i];
        }
        return result;
    }
};
