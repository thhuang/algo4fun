class Solution {
   public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> rank(n, 1);
        vector<int> group(n);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int u) -> int {
            if (group[u] == u) return u;
            return group[u] = find(group[u]);
        };

        function<void(int, int)> unite = [&](int a, int b) -> void {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return;
            if (rank[pa] > rank[pb]) {
                group[pb] = pa;
            } else if (rank[pa] < rank[pb]) {
                group[pa] = pb;
            } else {
                group[pb] = pa;
                ++rank[pa];
            }
        };

        for (vector<int>& road : roads) {
            unite(road[0] - 1, road[1] - 1);
        }

        vector<int> minScore(n, numeric_limits<int>::max());
        for (vector<int>& road : roads) {
            int g = find(road[0] - 1);
            minScore[g] = min(minScore[g], road[2]);
        }

        return minScore[find(0)];
    }
};
