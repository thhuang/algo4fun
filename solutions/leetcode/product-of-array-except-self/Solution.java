class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
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
}
