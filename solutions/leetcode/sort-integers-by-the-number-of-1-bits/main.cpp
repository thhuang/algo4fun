class Solution {
    int bitCount(int x) {
        int count = 0;
        while (x) ++count, x = x & (x - 1);
        return count;
    }

   public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), [&](int a, int b) -> bool {
            int ca = bitCount(a), cb = bitCount(b);
            if (ca == cb) return a < b;
            return bitCount(a) < bitCount(b);
        });

        return arr;
    }
};
