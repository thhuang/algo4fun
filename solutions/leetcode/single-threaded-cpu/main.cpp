class Solution {
    typedef long long ll;

    struct Cmp {
        bool operator()(pair<int, vector<int>*>& b,
                        pair<int, vector<int>*>& a) {
            if (a.second->at(1) != b.second->at(1)) {
                return a.second->at(1) < b.second->at(1);
            }
            return a.first < b.first;
        }
    };

   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<pair<int, vector<int>*>> order;
        for (int i = 0; i < n; ++i) order.push_back({i, &tasks[i]});

        sort(
            order.begin(), order.end(),
            [](pair<int, vector<int>*>& a, pair<int, vector<int>*>& b) -> bool {
                return a.second->at(0) < b.second->at(0);
            });

        vector<int> result;
        priority_queue<pair<int, vector<int>*>, vector<pair<int, vector<int>*>>, Cmp> q;
        ll t = 0;
        for (int i = 0; i < n || !q.empty();) {
            while (i < n && order[i].second->at(0) <= t) q.push(order[i++]);

            if (q.empty()) {
                int l = order[i].second->at(0);
                while (i < n && order[i].second->at(0) == l) q.push(order[i++]);
            }

            auto& p = q.top();
            t = max(t, (ll)p.second->at(0)) + p.second->at(1);
            result.push_back(p.first);
            q.pop();
        }

        return result;
    }
};
