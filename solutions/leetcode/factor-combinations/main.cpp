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

class Solution {
   public:
    vector<vector<int>> getFactors(int n) {
        vector<int> factors;

        for (int v = 2; v <= (int)sqrt(n); ++v) {
            if (n % v != 0) continue;
            factors.push_back(v);
            if (n / v == v) continue;
            factors.push_back(n / v);
        }

        if (factors.empty()) return {};

        vector<vector<int>> result;
        vector<int> curr;
        long long v = 1;
        function<void(int)> search = [&](int i) -> void {
            if (v == n) {
                result.push_back(curr);
                return;
            }
            if (v > n || i == factors.size()) return;

            search(i + 1);

            curr.push_back(factors[i]);
            v *= factors[i];
            search(i);
            v /= factors[i];
            curr.pop_back();
        };

        search(0);

        return result;
    }
};
