class Solution {
   public:
    int pathSum(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> tree;
        for (int v : nums) {
            int lv = v / 100;
            int pos = v % 100 / 10;
            int val = v % 10;
            tree[lv][pos] = val;
        }

        function<pair<int, int>(int, int)> dfs =
            [&](int lv, int pos) -> pair<int, int> {
            if (tree[lv].count(pos) == 0) {
                return {0, 0};
            }
            if (lv == 4) {
                return {tree[lv][pos], 1};
            }

            auto l = dfs(lv + 1, pos * 2 - 1);
            auto r = dfs(lv + 1, pos * 2);

            int pathCount = max(1, l.second + r.second);
            int sum = tree[lv][pos] * pathCount + l.first + r.first;

            return {sum, pathCount};
        };

        return dfs(1, 1).first;
    }
};

class Solution {
   public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> tree(5, vector<int>(9, -1));
        for (int v : nums) {
            int lv = v / 100;
            int pos = v % 100 / 10;
            int val = v % 10;
            tree[lv][pos] = val;
        }

        function<pair<int, int>(int, int)> dfs =
            [&](int lv, int pos) -> pair<int, int> {
            if (tree[lv][pos] == -1) {
                return {0, 0};
            }
            if (lv == 4) {
                return {tree[lv][pos], 1};
            }

            auto l = dfs(lv + 1, pos * 2 - 1);
            auto r = dfs(lv + 1, pos * 2);

            int pathCount = max(1, l.second + r.second);
            int sum = tree[lv][pos] * pathCount + l.first + r.first;

            return {sum, pathCount};
        };

        return dfs(1, 1).first;
    }
};
