class Solution {
   public:
    int countPrimes(int n) {
        int result = 0;
        vector<bool> valid(n, true);
        for (int i = 2; i < n; ++i) {
            if (!valid[i]) continue;
            ++result;
            for (int j = i; j < n; j += i) valid[j] = false;
        }
        return result;
    }
};

class Solution {
   public:
    int countPrimes(int n) {
        int result = 0;
        vector<bool> valid(n, true);
        for (int i = 2; i < n; ++i) {
            if (!valid[i]) continue;
            ++result;
            if (i > n / i) continue;
            for (int j = i * i; j < n; j += i) valid[j] = false;
        }
        return result;
    }
};
