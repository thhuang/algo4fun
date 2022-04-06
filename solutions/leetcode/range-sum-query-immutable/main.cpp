class NumArray {
    vector<int> prefix_sum;

   public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        prefix_sum = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            prefix_sum[i] = sum;
        }
    }

    int sumRange(int left, int right) {
        int sum = prefix_sum[right];
        if (left > 0) sum -= prefix_sum[left - 1];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
