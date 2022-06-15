class Solution {
   public:
    int numberOfPatterns(int m, int n) {
        vector<int> count(10, 0);
        bitset<10> curr;
        
        auto invalid = [&](int i, int j) -> bool {
            if (i > j) swap(i, j);
            if (i == 1) return (!curr[2] && j == 3) || (!curr[4] && j == 7) || (!curr[5] && j == 9);
            if (i == 2) return (!curr[5] && j == 8);
            if (i == 3) return (!curr[5] && j == 7) || (!curr[6] && j == 9);
            if (i == 4) return (!curr[5] && j == 6);
            if (i == 7) return (!curr[8] && j == 9);
            return false;
        };
        
        function<void(int, int)> dfs = [&](int u, int p) -> void {
            if (curr[u]) return;
            if (invalid(u, p)) return;
            if (curr.count() > n) return;
            
            curr[u] = 1;
            ++count[curr.count() - 1];
            for (int v = 1; v <= 9; ++v) dfs(v, u);
            curr[u] = 0;
        };
        dfs(0, 0);
        
        int result = 0;
        for (int i = m; i <= n; ++i) result += count[i];
        
        return result;
    }
};
