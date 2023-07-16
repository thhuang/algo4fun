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

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        function<void(int, int)> search = [&](int i, int t) -> void {
            if (t == 0) {
                result.push_back(combination);
                return;
            }
            if (i == candidates.size()) return;
            for (int j = i; j < candidates.size(); ++j) {
                if (candidates[j] > t) continue;
                combination.push_back(candidates[j]);
                search(j, t - candidates[j]);
                combination.pop_back();
            }
        };
        search(0, target);
        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<vector<int>> result;

        vector<int> curr;
        function<void(int, int)> dfs = [&](int i, int sum) -> void {
            if (sum == target) {
                result.push_back(curr);
                return;
            }
            if (i == n) return;

            int v = candidates[i];

            for (int k = 0; sum <= target; ++k, sum += v, curr.push_back(v))
                dfs(i + 1, sum);

            while (!curr.empty() && curr.back() == v) curr.pop_back();
        };

        dfs(0, 0);

        return result;
    }
};
