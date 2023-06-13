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

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int locked = n;
        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int u) -> void {
            if (vis[u]) return;
            vis[u] = true;
            --locked;
            for (int v : rooms[u]) dfs(v);
        };
        dfs(0);
        return locked == 0;
    }
};

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int cnt = rooms.size();
        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int u) -> void {
            if (vis[u]) return;
            vis[u] = true;
            for (int v : rooms[u]) dfs(v);
        };
        dfs(0);

        return reduce(vis.begin(), vis.end(), true,
                      [](bool b, bool r) -> bool { return b && r; });
    }
};
