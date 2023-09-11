class Solution {
    const int mod = 1e9 + 7;

   public:
    int countOrders(int n) {
        int pickups = 0;

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        memo[0][0] = 1;

        function<int(int, int)> search = [&](long long pickup,
                                             long long delivery) -> int {
            if (pickup < 0) return 0;
            if (pickup > delivery) return 0;
            if (memo[pickup][delivery] != -1) return memo[pickup][delivery];

            long long result = 0;

            (result += pickup * search(pickup - 1, delivery)) %= mod;
            (result += (delivery - pickup) * search(pickup, delivery - 1)) %=
                mod;

            return memo[pickup][delivery] = result;
        };

        return search(n, n);
    }
};
