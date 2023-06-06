class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int d = arr[1] - arr[0];
        for (int i = 2; i < arr.length; ++i) {
            if (arr[i] - arr[i - 1] != d) {
                return false;
            }
        }
        return true;
    }
}

class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int mx = Integer.MIN_VALUE;
        int mn = Integer.MAX_VALUE;
        for (int v : arr) {
            mx = Math.max(mx, v);
            mn = Math.min(mn, v);
        }

        int n = arr.length;
        if ((mx - mn) % (n - 1) != 0) {
            return false;
        }
        int d = (mx - mn) / (n - 1);
        if (d == 0) {
            return true;
        }

        boolean[] vis = new boolean[n];
        for (int v : arr) {
            int dv = v - mn;
            if (dv % d != 0) {
                return false;
            }

            int i = dv / d;
            if (vis[i]) {
                return false;
            }
            vis[i] = true;
        }

        return true;
    }
}



    
