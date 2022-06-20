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

class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        int n = candidates.size();

        vector<vector<int>> result;
        vector<int> curr;
        int sum = 0;
        function<void(int)> dfs = [&](int i) -> void {
            if (sum > target) return;
            if (i == candidates.size()) {
                if (sum == target) result.push_back(curr);
                return;
            }

            int v = candidates[i];
            int d = 1;
            while (i + d < n && candidates[i + d] == v) ++d;

            dfs(i + d);
            for (int j = 0; j < d; ++j) {
                curr.push_back(v);
                sum += v;
                dfs(i + d);
            }
            for (int j = 0; j < d; ++j) {
                sum -= v;
                curr.pop_back();
            }
        };

        dfs(0);

        return result;
    }
};
