class Solution {
    private ArrayList<Integer> rank;
    private ArrayList<Integer> group;

    int find(int k) {
        if (group.get(k) == k)
            return k;
        int v = find(group.get(k));
        group.set(k, v);
        return v;
    }

    void unite(int a, int b) {
        int ga = find(a);
        int gb = find(b);
        if (ga == gb)
            return;

        if (rank.get(ga) > rank.get(gb)) {
            group.set(gb, ga);
        } else if (rank.get(gb) > rank.get(ga)) {
            group.set(ga, gb);
        } else {
            rank.set(ga, rank.get(ga) + 1);
            group.set(gb, ga);
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;

        rank = new ArrayList<Integer>(n);
        for (int i = 0; i < n; ++i) {
            rank.add(0);
        }

        group = new ArrayList<Integer>(n);
        for (int i = 0; i < n; ++i) {
            group.add(i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    unite(i, j);
                }
            }
        }

        HashSet<Integer> provinces = new HashSet<Integer>();
        for (int i = 0; i < n; ++i) {
            provinces.add(find(i));
        }

        return provinces.size();
    }
}
