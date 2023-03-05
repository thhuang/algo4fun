class Solution {
   public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> numIndices;
        for (int i = 0; i < n; ++i) numIndices[arr[i]].push_back(i);

        vector<bool> vis(n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [i, step] = q.front();
            q.pop();

            if (i == n - 1) return step;

            if (vis[i]) continue;
            vis[i] = true;

            if (i + 1 < n) q.push({i + 1, step + 1});
            if (i - 1 >= 0) q.push({i - 1, step + 1});
            for (int j : numIndices[arr[i]]) {
                if (j == i) continue;
                q.push({j, step + 1});
            }
            numIndices.erase(arr[i]);
        }

        return -1;
    }
};
