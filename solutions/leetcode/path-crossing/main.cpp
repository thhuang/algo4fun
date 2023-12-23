class Solution {
   public:
    bool isPathCrossing(string path) {
        unordered_map<int, unordered_map<int, bool>> vis;

        int i = 0, j = 0;
        vis[i][j] = true;

        for (char dir : path) {
            switch (dir) {
                case 'N': {
                    --i;
                    break;
                }
                case 'S': {
                    ++i;
                    break;
                }
                case 'E': {
                    --j;
                    break;
                }
                case 'W': {
                    ++j;
                    break;
                }
            }
            if (vis[i][j]) return true;
            vis[i][j] = true;
        }
        return false;
    }
};
