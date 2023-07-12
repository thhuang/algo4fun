class Solution {
    enum class State { Unprocessed, Processing, Processed };

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& p : prerequisites) adj[p[0]].push_back(p[1]);

        vector<State> states(numCourses, State::Unprocessed);
        function<bool(int)> dfs = [&](int u) -> bool {
            if (states[u] == State::Processing) return false;
            if (states[u] == State::Processed) return true;
            states[u] = State::Processing;

            for (auto v : adj[u])
                if (!dfs(v)) return false;

            states[u] = State::Processed;
            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) return false;
        }

        return true;
    }
};
