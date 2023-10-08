/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
   public:
    int search(const ArrayReader& reader, int target) {
        int r = 1;
        while (reader.get(r) < target) r <<= 1;
        ++r;

        int l = 0;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (target < reader.get(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        int v = reader.get(l);
        return v == target ? l : -1;
    }
};
