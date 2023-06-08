class Solution {
    private static int lowerBound(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    private static int upperBound(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    public boolean isMajorityElement(int[] nums, int target) {
        int l = lowerBound(nums, target);
        int r = upperBound(nums, target);
        return r - l > nums.length / 2;
    }
}
