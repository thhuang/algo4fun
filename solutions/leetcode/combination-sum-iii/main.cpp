class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        int sum = 0;

        function<void(int)> search = [&](int i) -> void {
            if (combination.size() == k) {
                if (sum == n) result.push_back(combination);
                return;
            }
            if (i == 10) return;

            sum += i, combination.push_back(i);
            search(i + 1);
            sum -= i, combination.pop_back();
            search(i + 1);
        };

        search(1);

        return result;
    }
};
