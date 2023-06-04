class Solution {
    private class UnionFind {
        int[] rank;
        int[] group;

        UnionFind(int n) {
            rank = new int[n];
            group = new int[n];
            for (int i = 0; i < n; ++i) {
                group[i] = i;
            }
        }

        int find(int k) {
            if (group[k] == k) {
                return k;
            }
            return group[k] = find(group[k]);
        }

        boolean unite(int a, int b) {
            int ga = find(a);
            int gb = find(b);
            if (ga == gb) {
                return false;
            }

            if (rank[ga] < rank[gb]) {
                group[ga] = gb;
            } else if (rank[gb] < rank[ga]) {
                group[gb] = ga;
            } else {
                group[ga] = gb;
                ++rank[gb];
            }
            return true;
        }
    };

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        UnionFind uf = new UnionFind(n);

        int result = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 0) {
                    continue;
                }
                if (uf.unite(i, j)) {
                    --result;
                }
            }
        }

        return result;
    }

}

    
