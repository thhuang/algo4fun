class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 0) return true;

        vector<bool> vis(n, false);
        vector<int> keys = {0};
        while (!empty(keys)) {
            int u = keys.back();
            keys.pop_back();

            if (vis[u]) continue;
            vis[u] = true;

            if (--n == 0) return true;

            for (int v : rooms[u]) keys.push_back(v);
        }
        return false;
    }
};
