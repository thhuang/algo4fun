class Solution {
    public int longestSubarray(int[] nums) {
        int result = 0;
        for (int l = 0, r = 0, k = 1; r < nums.length; ++r) {
            if (nums[r] == 0) {
                --k;
            }
            if (k < 0) {
                while (nums[l++] != 0)
                    ;
                ++k;
            }
            result = Math.max(result, r - l);
        }
        return result;
    }
}
