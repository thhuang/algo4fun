class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(size(graph), 0);
        unordered_set<int> unsafe;

        function<bool(int)> search_unsafe = [&](int u) -> bool {
            if (vis[u] == 2) return unsafe.count(u);
            if (vis[u] == 1) {
                unsafe.insert(u);
                return true;
            }

            vis[u] = 1;
            bool is_unsafe = false;
            for (int v : graph[u]) {
                if (search_unsafe(v)) {
                    unsafe.insert(u);
                    is_unsafe = true;
                }
            }
            vis[u] = 2;

            return is_unsafe;
        };

        for (int i = 0; i < size(graph); ++i) search_unsafe(i);

        vector<int> ans;
        for (int i = 0; i < size(graph); ++i) {
            if (unsafe.count(i)) continue;
            ans.push_back(i);
        }

        return ans;
    }
};

class Solution {
    enum class State { Unknown, Unsafe, Safe };

   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> result;

        vector<State> states(n, State::Unknown);
        function<bool(int)> dfs = [&](int u) -> bool {
            if (states[u] == State::Unsafe) return false;
            if (states[u] == State::Safe) return true;
            states[u] = State::Unsafe;

            bool isSafe = true;
            for (int v : graph[u]) isSafe = dfs(v) && isSafe;

            if (!isSafe) return false;
            states[u] = State::Safe;
            return true;
        };

        for (int i = 0; i < n; ++i)
            if (dfs(i)) result.push_back(i);

        return result;
    }
};
