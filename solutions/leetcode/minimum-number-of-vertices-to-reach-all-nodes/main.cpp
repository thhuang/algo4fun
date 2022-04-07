class Solution {
   public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> reachable;
        for (auto e : edges) reachable.insert(e[1]);

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (reachable.count(i)) continue;
            result.push_back(i);
        }

        return result;
    }
};
