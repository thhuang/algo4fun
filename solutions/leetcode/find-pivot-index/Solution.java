class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for (int v : nums) {
            sum += v;
        }
        for (int i = 0, v = 0; i < nums.length; ++i) {
            if (v * 2 + nums[i] == sum) {
                return i;
            }
            v += nums[i];
        }
        return -1;
    }
}
