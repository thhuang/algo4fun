class Solution {
   public:
    int findIntegers(int n) {
        vector<int> valid = {0, 1};

        for (int i = 1; i < valid.size(); ++i) {
            int v = valid[i];

            if (v * 2 <= n) valid.push_back(v * 2);
            if (v % 2 == 0 and v * 2 + 1 <= n) valid.push_back(v * 2 + 1);
        }

        return valid.size();
    }
};

class Solution {
   public:
    int findIntegers(int n) {
        vector<int> fib(32);
        fib[0] = 1, fib[1] = 2;
        for (int i = 2; i < fib.size(); ++i) fib[i] = fib[i - 1] + fib[i - 2];

        int result = 0;
        bitset<31> b(n);
        for (int i = 31, prev = 0; i >= 0; --i) {
            if (b[i] == 1) {
                result += fib[i];
                if (prev == 1) return result;
                prev = 1;
            } else {
                prev = 0;
            }
        }

        return result + 1;
    }
};
