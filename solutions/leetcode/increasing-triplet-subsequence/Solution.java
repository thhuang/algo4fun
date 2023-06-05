class Solution {
    public boolean increasingTriplet(int[] nums) {
        int a = Integer.MAX_VALUE;
        int b = Integer.MAX_VALUE;
        for (int v : nums) {
            if (v <= a) {
                a = v;
            } else if (v <= b) {
                b = v;
            } else {
                return true;
            }
        }
        return false;
    }
}
