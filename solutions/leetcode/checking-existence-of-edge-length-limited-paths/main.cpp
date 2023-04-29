class Solution {
   public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        vector<int> rank(n, 0);
        vector<int> group(n);
        iota(group.begin(), group.end(), 0);

        function<int(int)> find = [&](int k) -> int {
            if (k == group[k]) return k;
            return group[k] = find(group[k]);
        };

        function<void(int, int)> unite = [&](int a, int b) -> void {
            int ga = find(a);
            int gb = find(b);
            if (ga == gb) return;
            if (rank[ga] > rank[gb]) {
                group[gb] = ga;
            } else if (rank[gb] > rank[ga]) {
                group[ga] = gb;
            } else {
                group[gb] = ga;
                ++rank[ga];
            }
        };

        function<bool(int, int)> isConnected = [&](int a, int b) -> bool {
            return find(a) == find(b);
        };

        sort(edgeList.begin(), edgeList.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool {
                 return a[2] < b[2];
             });

        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); ++i) {
            q.push_back({i, queries[i][0], queries[i][1], queries[i][2]});
        }
        sort(q.begin(), q.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool {
                 return a[3] < b[3];
             });

        vector<bool> result(q.size());
        int ei = 0, qi = 0;
        while (qi < q.size()) {
            int limit = q[qi][3];
            while (ei < edgeList.size() && edgeList[ei][2] < limit) {
                unite(edgeList[ei][0], edgeList[ei][1]);
                ++ei;
            }
            result[q[qi][0]] = isConnected(q[qi][1], q[qi][2]);
            ++qi;
        }

        return result;
    }
};
