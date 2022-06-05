class Solution {
   public:
    int twoEggDrop(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        static unordered_map<int, int> cache;
        if (cache.count(n)) return cache[n];

        int result = numeric_limits<int>::max();
        for (int i = 1; i <= n; ++i) {
            int v = max(i, 1 + twoEggDrop(n - i));
            result = min(result, v);
        }

        return cache[n] = result;
    }
};
