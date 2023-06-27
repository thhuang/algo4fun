class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        int m = nums1.size(), n = nums2.size();

        unordered_map<int, unordered_map<int, bool>> vis;
        vector<vector<int>> result;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({nums1[0] + nums2[0], 0, 0});
        while (!pq.empty() && result.size() < k) {
            auto [v, i, j] = pq.top();
            pq.pop();

            if (vis[i][j]) continue;
            vis[i][j] = true;

            result.push_back({nums1[i], nums2[j]});
            if (i + 1 < m) pq.push({nums1[i + 1] + nums2[j], i + 1, j});
            if (j + 1 < n) pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }

        return result;
    }
};
