class Solution {
   public:
    int countVowelStrings(int n) {
        array<int, 5> dp = {1, 1, 1, 1, 1};
        for (int i = 2; i <= n; ++i) {
            array<int, 5> new_dp = {0, 0, 0, 0, 0};
            for (int j = 0; j < 5; ++j) {
                for (int k = 4; k >= j; --k) {
                    new_dp[k] += dp[j];
                }
            }
            dp = move(new_dp);
        }

        int result = 0;
        for (int v : dp) result += v;

        return result;
    }
};

class Solution {
   public:
    int countVowelStrings(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        while (--n) {
            e += a;
            i += e;
            o += i;
            u += o;
        }
        return a + e + i + o + u;
    }
};

class Solution {
   public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};
