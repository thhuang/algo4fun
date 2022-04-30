class Solution {
   public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> factors;

        function<void(int, int)> search = [&](int l, int r) -> void {
            if (r == 1) {
                result.push_back(factors);
                return;
            }
            for (int i = l; i <= r; ++i) {
                if (r % i != 0) continue;
                factors.push_back(i);
                search(i, r / i);
                factors.pop_back();
            }
        };

        search(2, n);
        result.pop_back();

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> factors;

        function<void(int, int)> search = [&](int l, int r) -> void {
            for (int i = l; i * i <= r; ++i) {
                if (r % i != 0) continue;
                factors.push_back(i);

                result.push_back(factors);
                result.back().push_back(r / i);

                search(i, r / i);
                factors.pop_back();
            }
        };

        search(2, n);

        return result;
    }
};
