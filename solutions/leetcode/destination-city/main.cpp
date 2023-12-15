class Solution {
   public:
    string destCity(vector<vector<string>>& paths) {
        string result;
        unordered_map<string, bool> vis;
        for (auto& path : paths) {
            vis[path[0]] = true;
        }
        for (auto& path : paths) {
            if (!vis[path[1]]) {
                return path[1];
            }
        }
        return "";
    }
};
