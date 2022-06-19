class Solution {
   public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        if (num % 10 != 0 && k == 0) return -1;

        int count = 0;
        while (num >= 0) {
            num -= k;
            ++count;
            if (num % 10 != 0) continue;
            return count;
        }
        return -1;
    }
};
