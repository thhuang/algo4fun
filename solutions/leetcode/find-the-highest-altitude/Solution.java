class Solution {
    public int largestAltitude(int[] gain) {
        int result = 0;
        int h = 0;
        for (int v : gain) {
            h += v;
            result = Math.max(result, h);
        }
        return result;
    }
}
