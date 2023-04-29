/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has
 * value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements
 * have a value equal to 1. int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
   public:
    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        int equal = 1, different = 0;
        int opposite = -1;

        auto update = [&](int i, bool isSame) -> void {
            if (isSame) {
                ++equal;
            } else {
                ++different;
                opposite = i;
            }
        };

        int q0123 = reader.query(0, 1, 2, 3);
        int q1234 = reader.query(1, 2, 3, 4);
        for (int i = 4; i < n; ++i) {
            update(i, reader.query(1, 2, 3, i) == q0123);
        }
        update(1, q1234 == reader.query(0, 2, 3, 4));
        update(2, q1234 == reader.query(0, 1, 3, 4));
        update(3, q1234 == reader.query(0, 1, 2, 4));

        if (equal == different) return -1;
        return equal > different ? 0 : opposite;
    }
};
