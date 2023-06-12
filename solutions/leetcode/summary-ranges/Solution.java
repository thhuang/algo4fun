class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<String>();

        for (int l = 0, r = 0; l < nums.length;) {
            while (r < nums.length && (long) nums[l] + r - l == nums[r]) {
                ++r;
            }

            if (r - l == 1) {
                result.add(String.valueOf(nums[l]));
            } else {
                result.add(String.valueOf(nums[l]) + "->" + String.valueOf(nums[r - 1]));
            }

            l = r;
        }

        return result;
    }
}
