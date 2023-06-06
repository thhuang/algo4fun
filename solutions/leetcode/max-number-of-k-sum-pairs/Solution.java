class Solution {
    public int maxOperations(int[] nums, int k) {
        int result = 0;
        HashMap<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for (int v : nums) {
            if (cnt.getOrDefault(v, 0) == 0) {
                cnt.put(k - v, cnt.getOrDefault(k - v, 0) + 1);
            } else {
                cnt.put(v, cnt.get(v) - 1);
                ++result;
            }
        }
        return result;
    }
}
