/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
   public:
    int getIndex(ArrayReader &reader) {
        int l = 0, r = reader.length();

        while (r - l > 1) {
            int m = l + (r - l) / 2;

            bool odd = (r - l) % 2 == 1;
            if (odd) {
                int res = reader.compareSub(l, m - 1, m + 1, r - 1);
                if (res == 0) {
                    return m;
                } else if (res < 0) {
                    l = m + 1;
                } else {
                    r = m;
                }
            } else {
                int res = reader.compareSub(l, m - 1, m, r - 1);
                if (res < 0) {
                    l = m;
                } else {
                    r = m;
                }
            }
        }

        return l;
    }
};
