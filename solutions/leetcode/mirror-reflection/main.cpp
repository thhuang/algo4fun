class Solution {
   public:
    int mirrorReflection(int p, int q) {
        int v = gcd(p, q);
        p /= v, q /= v;

        if (q % 2 == 0) return 0;
        if (p % 2 == 0) return 2;
        return 1;
    }
};
