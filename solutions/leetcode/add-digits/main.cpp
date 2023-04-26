class Solution {
   public:
    int addDigits(int num) {
        while (num >= 10) {
            int v = 0;
            while (num > 0) {
                v += num % 10;
                num /= 10;
            }
            num = v;
        }
        return num;
    }
};

class Solution {
   public:
    int addDigits(int num) {
        if (num < 10) return num;
        return addDigits(num % 10 + num / 10);
    }
};
