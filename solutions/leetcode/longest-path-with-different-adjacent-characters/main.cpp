class Solution {
   public:
    int longestPath(vector<int>& parent, string s) {
        int result = 0;

        int n = s.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) children[parent[i]].push_back(i);

        function<int(int)> dfs = [&](int u) -> int {
            vector<int> length = {1};
            for (int v : children[u]) {
                int l = dfs(v);
                if (s[v] == s[u]) {
                    result = max(result, l);
                } else {
                    length.push_back(l + 1);
                }
            }

            sort(length.begin(), length.end(), greater<>());
            int l = length[0];
            if (length.size() > 1) l += length[1] - 1;
            result = max(result, l);

            return length.front();
        };

        dfs(0);

        return result;
    }
};
