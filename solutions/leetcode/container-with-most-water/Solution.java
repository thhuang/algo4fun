class Solution {
    public int maxArea(int[] height) {
        int result = 0;
        int l = 0, r = height.length - 1;
        while (l < r) {
            int hl = height[l], hr = height[r];
            result = Math.max(result, (r - l) * Math.min(hl, hr));
            if (hl < hr) {
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }
}
