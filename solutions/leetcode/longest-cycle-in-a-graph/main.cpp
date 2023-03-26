class Solution {
   public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int result = -1;

        unordered_set<int> visited;
        visited.insert(-1);

        for (int i = 0; i < n; ++i) {
            if (visited.count(i) > 0) continue;

            unordered_map<int, int> mp;
            for (int v = 0, j = i; true; ++v) {
                if (visited.count(j) > 0) {
                    for (auto [k, _] : mp) visited.insert(k);
                    break;
                }

                if (mp.count(j) == 0) {
                    mp[j] = v;
                    j = edges[j];
                    continue;
                }

                result = max(result, v - mp[j]);
                for (auto [k, _] : mp) visited.insert(k);
                break;
            }
        }

        return result;
    }
};
