class Solution {
   public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < pid.size(); ++i) graph[ppid[i]].push_back(pid[i]);

        vector<int> result;
        deque<int> to_be_killed = {kill};
        while (!to_be_killed.empty()) {
            int u = to_be_killed.front();
            to_be_killed.pop_front();

            result.push_back(u);

            for (int v : graph[u]) to_be_killed.push_back(v);
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; ++i) adj[ppid[i]].push_back(pid[i]);

        vector<int> result;
        function<void(int)> dfs = [&](int u) -> void {
            result.push_back(u);
            for (int v : adj[u]) dfs(v);
        };

        dfs(kill);

        return result;
    }
};
