class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        while (n != 1) {
            if (vis.count(n)) return false;
            vis.insert(n);

            int m = 0;
            while (n) {
                int digit = n % 10;
                m += digit * digit;
                n /= 10;
            }
            n = m;
        }
        return true;
    }
};
