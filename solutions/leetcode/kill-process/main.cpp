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
