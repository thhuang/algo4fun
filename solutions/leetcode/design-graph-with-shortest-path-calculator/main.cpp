class Graph {
    static const int MAX = 1e9;

    int n;
    vector<vector<long long>> d;

   public:
    Graph(int n, vector<vector<int>>& edges)
        : n(n), d(n, vector<long long>(n, MAX)) {
        for (int i = 0; i < n; ++i) d[i][i] = 0;
        for (vector<int> e : edges) d[e[0]][e[1]] = e[2];
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][edge[0]] + edge[2] + d[edge[1]][j]);
            }
        }
    }

    int shortestPath(int node1, int node2) {
        int result = d[node1][node2];
        if (result >= MAX) return -1;
        return result;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
