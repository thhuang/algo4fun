class Solution {
   public:
    bool isUgly(int n) {
        if (n < 1) return false;
        int result = process(process(process(n, 2), 3), 5);
        return result == 1;
    }

    int process(int n, int prime) {
        while (n % prime == 0) {
            n /= prime;
        }
        return n;
    }
};
