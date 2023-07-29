class Solution {
   public:
    double soupServings(int n) {
        if (n >= 5000) return 1;
        unordered_map<int, unordered_map<int, double>> memo;
        function<double(int, int)> f = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5;
            if (a <= 0) return 1;
            if (b <= 0) return 0;
            if (memo[a].count(b)) return memo[a][b];
            return memo[a][b] = 0.25 * (f(a - 100, b) + f(a - 75, b - 25) +
                                        f(a - 50, b - 50) + f(a - 25, b - 75));
        };
        return f(n, n);
    }
};
