class Solution {
    enum class State { processed, processing, unprocessed };

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<State> states(numCourses, State::unprocessed);
        function<bool(int)> dfs = [&](int u) -> bool {
            if (states[u] == State::processing) return false;
            if (states[u] == State::processed) return true;
            states[u] = State::processing;
            for (int v : adj[u]) {
                if (!dfs(v)) return false;
            }
            states[u] = State::processed;
            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) return false;
        }

        return true;
    }
};
