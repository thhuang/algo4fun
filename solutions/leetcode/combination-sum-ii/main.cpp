class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> num_count;
        for (int v : candidates) ++num_count[v];

        vector<vector<int>> result;
        vector<int> combination;
        int sum = 0;

        function<void(unordered_map<int, int>::iterator)> search =
            [&](unordered_map<int, int>::iterator it) -> void {
            if (sum > target) return;
            if (sum == target) {
                result.push_back(combination);
                return;
            }
            if (it == num_count.end()) return;

            auto next_it = it;
            ++next_it;
            search(next_it);

            for (int i = 0; i < it->second; ++i) {
                sum += it->first;
                combination.push_back(it->first);
                search(next_it);
            }
            for (int i = 0; i < it->second; ++i) {
                sum -= it->first;
                combination.pop_back();
            }
        };

        search(num_count.begin());

        return result;
    }
};
