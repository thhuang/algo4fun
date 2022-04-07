class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unordered_set<int>> graph(n);
        vector<unordered_set<int>> rgraph(n);
        for (auto edge : trust) {
            --edge[0], --edge[1];
            graph[edge[0]].insert(edge[1]);
            rgraph[edge[1]].insert(edge[0]);
        }

        int judge = -1;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].size() > 0) continue;
            if (~judge) return -1;
            if (rgraph[i].size() != n - 1) return -1;
            return i + 1;
        }

        return ~judge ? judge + 1 : -1;
    }
};

class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n + 1);
        for (auto p : trust) {
            --count[p[0]];
            ++count[p[1]];
        }
        for (int i = 1; i <= n; ++i) {
            if (count[i] == n - 1) return i;
        }
        return -1;
    }
};
