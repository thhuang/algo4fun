class Solution {
   public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int m = strs.front().size();

        vector<int> rank(n, 0);
        vector<int> group(n);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int k) -> int {
            if (k == group[k]) return k;
            return group[k] = find(group[k]);
        };

        function<bool(int, int)> unite = [&](int a, int b) -> bool {
            int ga = find(a);
            int gb = find(b);
            if (ga == gb) return false;
            if (rank[ga] > rank[gb]) {
                group[gb] = ga;
            } else if (rank[gb] > rank[ga]) {
                group[ga] = gb;
            } else {
                group[gb] = ga;
                ++rank[ga];
            }
            return true;
        };

        int result = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = 0;
                for (int k = 0; k < m; ++k) {
                    if (strs[i][k] != strs[j][k]) ++diff;
                    if (diff > 2) break;
                }
                if (diff > 2) continue;
                if (unite(i, j)) --result;
            }
        }

        return result;
    }
};
