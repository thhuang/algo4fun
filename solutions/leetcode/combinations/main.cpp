class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;

        vector<int> combination;
        function<void(int)> search = [&](int i) -> void {
            if (combination.size() == k) {
                result.push_back(combination);
                return;
            }

            if (i > n) return;
            search(i + 1);
            combination.push_back(i);
            search(i + 1);
            combination.pop_back();
        };

        search(1);

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;

        vector<int> combination;
        function<void(int)> search = [&](int i) -> void {
            if (combination.size() == k) {
                result.push_back(combination);
                return;
            }

            if (combination.size() + n - i + 1 < k) return;

            search(i + 1);
            combination.push_back(i);
            search(i + 1);
            combination.pop_back();
        };

        search(1);

        return result;
    }
};
