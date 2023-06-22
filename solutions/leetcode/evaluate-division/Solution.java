class Solution {
    HashMap<String, HashMap<String, Double>> adj;
    HashSet<String> vis;
    

    private double dfs(String a, String t) {
        if (a == t) return 0.0;
        if (!adj.containsKey(a)) return -1.0;
        if (adj.get(a).containsKey(t)) return adj.get(a).get(t);
        if (vis.contains(a)) return -1.0;
        vis.add(a);
        for (var bv : adj.get(a).entrySet()) {
            var b = bv.getKey();
            var v = bv.getValue();
            if (v < 0) continue;

            var got = dfs(b, t);
            if (got < 0) continue;

            var res = v * got;
            adj.get(a).put(t, res);
            return res;
        }
        return -1.0;
    }

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        adj = new HashMap<>();

        for (int i = 0; i < equations.size(); ++i) {
            var a = equations.get(i).get(0);
            var b = equations.get(i).get(1);
            var v = values[i];

            if (!adj.containsKey(a)) adj.put(a, new HashMap<String, Double>());
            if (!adj.containsKey(b)) adj.put(b, new HashMap<String, Double>());
            
            adj.get(a).put(b, v);
            if (v != 0) adj.get(b).put(a, 1.0 / v);
        }

        var result = new double[queries.size()];
        for (int i = 0; i < queries.size(); ++i) {
            vis = new HashSet<String>();

            var a = queries.get(i).get(0);
            var b = queries.get(i).get(1);

            if (!adj.containsKey(a) || !adj.containsKey(b)) {
                result[i] = -1.0;
            } else {
                result[i] = dfs(a, b);
            }
        }

        return result;
    }
}
