class Solution {
   public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {
        vector<bool> hasParent(n, false);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) hasParent[leftChild[i]] = true;
            if (rightChild[i] != -1) hasParent[rightChild[i]] = true;
        }

        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (hasParent[i]) continue;
            if (root != -1) return false;
            root = i;
        }
        if (root == -1) return false;

        vector<bool> vis(n, false);
        function<bool(int)> dfs = [&](int u) -> bool {
            if (vis[u]) return false;
            vis[u] = true;
            if (leftChild[u] != -1 && !dfs(leftChild[u])) return false;
            if (rightChild[u] != -1 && !dfs(rightChild[u])) return false;
            return true;
        };
        if (!dfs(root)) return false;

        for (bool b : vis) {
            if (!b) return false;
        }

        return true;
    }
};
