class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double result = -1e9;
        double curr = 0;
        for (int i = 0; i < k - 1; ++i) {
            curr += nums[i];
        }
        for (int i = k - 1; i < nums.length; ++i) {
            curr += nums[i];
            result = Math.max(result, curr);
            curr -= nums[i - k + 1];
        }
        return result / k;
    }
}
