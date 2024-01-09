/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
   public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int m = dim[0], n = dim[1];
        int j = n - 1;
        for (int i = 0; i < m && j >= 0; ++i) {
            while (j >= 0 && binaryMatrix.get(i, j) == 1) --j;
        }
        ++j;
        if (j == n) return -1;
        return j;
    }
};

class Solution {
   public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dim = binaryMatrix.dimensions();
        int rows = dim[0];
        int cols = dim[1];

        int result = cols;

        for (int i = 0; i < rows; ++i) {
            int l = -1, r = cols;
            while (r - l > 1) {
                int m = l + (r - l) / 2;
                if (binaryMatrix.get(i, m) == 1) {
                    r = m;
                } else {
                    l = m;
                }
            }
            result = min(result, r);
        }

        return result < cols ? result : -1;
    }
};
