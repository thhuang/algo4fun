/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int findMaxIndex(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 1, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (mountainArr.get(m - 1) < mountainArr.get(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }

   public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int h = findMaxIndex(mountainArr);

        {
            int l = 0, r = h;
            while (l <= r) {
                int m = l + (r - l) / 2;
                int v = mountainArr.get(m);
                if (v == target) return m;
                if (target < v) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        {
            int l = h, r = mountainArr.length() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                int v = mountainArr.get(m);
                if (v == target) return m;
                if (target < v) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};
