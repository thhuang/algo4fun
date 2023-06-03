class Solution {
    ArrayList<ArrayList<Integer>> subordinates;
    int result;
    int[] informTime;

    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        this.subordinates = new ArrayList<ArrayList<Integer>>(n);
        this.informTime = informTime;
        this.result = 0;

        for (int i = 0; i < n; ++i) {
            this.subordinates.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < n; ++i) {
            if (i == headID)
                continue;
            this.subordinates.get(manager[i]).add(i);
        }

        dfs(headID, 0);

        return this.result;
    }

    private void dfs(int u, int t) {
        this.result = Math.max(this.result, t);
        for (int v : subordinates.get(u)) {
            dfs(v, t + this.informTime[u]);
        }
    }
}
