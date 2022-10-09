class Solution {
   public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int result = 0, time = 0;
        for (int i = 0, p = 0; i < logs.size(); ++i) {
            int id = logs[i][0];
            int t = logs[i][1];
            if (int v = t - p; v >= time) {
                result = v == time ? min(result, id) : id;
                time = t - p;
            }
            p = t;
        }
        return result;
    }
};
