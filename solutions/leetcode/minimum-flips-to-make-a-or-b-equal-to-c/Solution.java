class Solution {
    public int minFlips(int a, int b, int c) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            boolean aa = (a & mask) != 0;
            boolean bb = (b & mask) != 0;
            boolean cc = (c & mask) != 0;
            if (cc) {
                if (aa || bb) {
                    continue;
                }
                ++result;
            } else {
                if (aa) {
                    ++result;
                }
                if (bb) {
                    ++result;
                }
            }
        }
        return result;
    }
}
