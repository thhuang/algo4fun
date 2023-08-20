class Solution {
    struct UnionFind {
        vector<int> parent;
        vector<int> rank;
        vector<int> size;
        int maxSize = 1;

        UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int k) {
            if (parent[k] == k) return k;
            return parent[k] = find(parent[k]);
        }

        bool unite(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return false;

            if (rank[pa] < rank[pb]) swap(pa, pb);

            parent[pb] = pa;
            maxSize = max(maxSize, size[pa] += size[pb]);

            if (rank[pa] == rank[pb]) ++rank[pa];

            return true;
        }
    };

   public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(),
             [](const auto& a, const auto& b) -> bool { return a[2] < b[2]; });

        int minWeight = 0;
        UnionFind ufMST(n);
        for (const auto& e : edges) {
            if (ufMST.unite(e[0], e[1])) {
                minWeight += e[2];
            }
        }

        vector<vector<int>> result(2);

        for (int i = 0; i < m; ++i) {
            int reducedWeight = 0;
            UnionFind ufReducedMST(n);
            for (int j = 0; j < m; ++j) {
                if (i != j && ufReducedMST.unite(edges[j][0], edges[j][1])) {
                    reducedWeight += edges[j][2];
                }
            }

            if (ufReducedMST.maxSize < n || reducedWeight > minWeight) {
                result[0].push_back(edges[i][3]);
                continue;
            }

            int forcedWeight = edges[i][2];
            UnionFind ufForcedMST(n);
            ufForcedMST.unite(edges[i][0], edges[i][1]);
            for (int j = 0; j < m; ++j) {
                if (i != j && ufForcedMST.unite(edges[j][0], edges[j][1])) {
                    forcedWeight += edges[j][2];
                }
            }

            if (forcedWeight == minWeight) {
                result[1].push_back(edges[i][3]);
            }
        }

        return result;
    }
};
