class Solution {
   public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        unordered_map<int, int> mp;
        for (int i = 0, t = 0; i < logs.size(); ++i) {
            int id = logs[i][0];
            int time = logs[i][1];
            mp[id] = max(mp[id], time - t);
            t = time;
        }

        int result = 0, time = 0;
        for (auto [id, t] : mp) {
            if (t > time) {
                result = id;
                time = t;
            } else if (t == time && id < result) {
                result = id;
            }
        }

        return result;
    }
};
