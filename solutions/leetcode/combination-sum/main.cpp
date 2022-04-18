class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        int sum = 0;
        function<void(int)> search = [&](int i) -> void {
            if (sum > target) return;
            if (sum == target) {
                result.push_back(combination);
                return;
            }
            if (i == candidates.size()) return;

            int v = candidates[i];
            int n = (target - sum) / v;

            search(i + 1);
            for (int j = 0; j < n; ++j) {
                sum += v;
                combination.push_back(v);
                search(i + 1);
            }
            for (int j = 0; j < n; ++j) {
                sum -= v;
                combination.pop_back();
            }
        };

        search(0);

        return result;
    }
};
