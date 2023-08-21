class Solution {
    enum class State { unprocessed, processing, processed };

    bool dfs(int u, vector<unordered_set<int>>& adj, vector<int>& dag,
             vector<State>& state) {
        if (state[u] == State::processing) return false;
        if (state[u] == State::processed) return true;

        state[u] = State::processing;

        for (int v : adj[u]) {
            if (!dfs(v, adj, dag, state)) return false;
        }

        state[u] = State::processed;
        dag.push_back(u);

        return true;
    }

   public:
    vector<int> sortItems(int n, int m, vector<int>& group,
                          vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) group[i] = m++;
        }

        vector<unordered_set<int>> gAdj(m);
        vector<unordered_set<int>> iAdj(n);
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                if (group[i] == group[j]) {
                    iAdj[i].insert(j);
                } else {
                    gAdj[group[i]].insert(group[j]);
                }
            }
        }

        vector<int> dag;
        {
            vector<State> state(m, State::unprocessed);
            for (int i = 0; i < m; ++i) {
                if (!dfs(i, gAdj, dag, state)) return {};
            }
        }

        vector<unordered_set<int>> g2i(m);
        for (int i = 0; i < n; ++i) {
            g2i[group[i]].insert(i);
        }

        vector<int> result;
        for (int g : dag) {
            vector<State> state(n, State::unprocessed);
            for (int i : g2i[g]) {
                if (!dfs(i, iAdj, result, state)) return {};
            }
        }

        return result;
    }
};
