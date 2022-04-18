class Solution {
   public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs.front().size();

        vector<int> cost(k, 0);
        for (vector<int>& curr_cost : costs) {
            vector<int> new_cost(k, 0);
            multiset<int> prev_cost;
            for (int c : cost) prev_cost.insert(c);

            for (int i = 0; i < k; ++i) {
                int c = cost[i];
                prev_cost.erase(prev_cost.find(c));
                new_cost[i] = curr_cost[i] + *prev_cost.begin();
                prev_cost.insert(c);
            }

            cost = move(new_cost);
        }

        return *min_element(cost.begin(), cost.end());
    }
};
