class Solution {
   public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n > 1) {
            if (n % 4) return false;
            n /= 4;
        }
        return true;
    }
};

class Solution {
   public:
    bool isPowerOfFour(int n) {
        long long v = 1;
        while (v < n) v *= 4;
        return v == n;
    }
};

class Solution {
   public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        double v = log(n) / log(4);
        return v == (int)v;
    }
};

class Solution {
   public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (__builtin_popcount(n) != 1) return false;
        if (__builtin_ctz(n) % 2) return false;
        return true;
    }
};
