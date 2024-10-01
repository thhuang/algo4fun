class Solution {
    public boolean canArrange(int[] arr, int k) {
        int n = arr.length / 2;
        Map<Integer, Integer> mp = new HashMap<>();

        for (int v : arr) {
            int r = (v % k + k) % k;
            int t = (k - r) % k;
            if (mp.getOrDefault(t, 0) > 0) {
                mp.put(t, mp.get(t) - 1);
                --n;
            } else {
                mp.put(r, mp.getOrDefault(r, 0) + 1);
            }
        }

        return n == 0;
    }
}

class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] freq = new int[k];

        for (int v : arr) {
            int r = (v % k + k) % k;
            ++freq[r];
        }

        if (freq[0] % 2 != 0) {
            return false;
        }

        for (int i = 1; i <= k / 2; ++i) {
            if (freq[i] != freq[k - i]) {
                return false;
            }
        }

        return true;
    }
}