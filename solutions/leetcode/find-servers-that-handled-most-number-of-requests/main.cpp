class Solution {
   public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);

        set<int> idle;
        for (int i = 0; i < k; ++i) idle.insert(i);

        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> endtime_server;

        int max_count = 0;
        for (int i = 0; i < arrival.size(); ++i) {
            while (!endtime_server.empty() &&
                   endtime_server.top()[0] < arrival[i]) {
                idle.insert(endtime_server.top()[1]);
                endtime_server.pop();
            }

            if (idle.empty()) continue;

            auto it = idle.lower_bound(i % k);
            if (it == idle.end()) it = idle.begin();

            max_count = max(max_count, ++count[*it]);
            endtime_server.push({arrival[i] + load[i] - 1, *it});
            idle.erase(*it);
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_count) result.push_back(i);
        }

        return result;
    }
};
