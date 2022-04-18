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

class Solution {
   public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs.front().size();

        multiset<int> prev_min;
        prev_min.insert(0), prev_min.insert(0);
        int prev_min_idx = 0;
        for (vector<int>& cost : costs) {
            multiset<int> new_min;
            int new_min_idx = -1;
            for (int i = 0; i < k; ++i) {
                int prev = (i == prev_min_idx) ? *prev_min.rbegin()
                                               : *prev_min.begin();
                int c = cost[i] + prev;
                new_min.insert(c);
                if (new_min.size() > 2) new_min.erase(++ ++new_min.begin());
                if (c == *new_min.begin()) new_min_idx = i;
            }
            prev_min = move(new_min);
            prev_min_idx = new_min_idx;
        }

        return *prev_min.begin();
    }
};
