class Solution {
   public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);

        deque<int> q = {start};
        while (!q.empty()) {
            int u = q.front();
            q.pop_front();

            if (u < 0 || u >= n) continue;
            if (vis[u]) continue;
            if (arr[u] == 0) return true;

            vis[u] = true;

            q.push_back(u + arr[u]);
            q.push_back(u - arr[u]);
        }

        return false;
    }
};
