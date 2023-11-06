class Solution {
    enum class State { unprocessed, processing, processed };

   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const vector<int>& pr : prerequisites) {
            adj[pr[1]].push_back(pr[0]);
        }

        vector<int> rresult;

        vector<State> states(numCourses, State::unprocessed);
        function<bool(int)> dfs = [&](int u) -> bool {
            if (states[u] == State::processed) return true;
            if (states[u] == State::processing) return false;

            states[u] = State::processing;

            for (int v : adj[u]) {
                if (!dfs(v)) return false;
            }
            rresult.push_back(u);

            states[u] = State::processed;
            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) return {};
        }

        return {rresult.rbegin(), rresult.rend()};
    }
};
