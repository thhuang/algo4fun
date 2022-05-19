class Solution {
    unordered_map<char, function<int(int, int)>> ops = {
        {'+', [](int a, int b) -> int { return a + b; }},
        {'-', [](int a, int b) -> int { return a - b; }},
        {'*', [](int a, int b) -> int { return a * b; }},
    };

   public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> operators;

        int v = 0;
        for (char c : expression) {
            if (isdigit(c)) {
                v = v * 10 + c - '0';
            } else {
                operators.push_back(c);
                nums.push_back(v);
                v = 0;
            }
        }
        nums.push_back(v);

        function<vector<int>(int, int)> process = [&](int l,
                                                      int r) -> vector<int> {
            if (l == r) return {nums[l]};

            vector<int> result;
            for (int i = l; i < r; ++i) {
                for (int a : process(l, i)) {
                    for (int b : process(i + 1, r)) {
                        result.push_back(ops[operators[i]](a, b));
                    }
                }
            }

            return result;
        };

        return process(0, nums.size() - 1);
    }
};

class Solution {
    unordered_map<char, function<int(int, int)>> ops = {
        {'+', [](int a, int b) -> int { return a + b; }},
        {'-', [](int a, int b) -> int { return a - b; }},
        {'*', [](int a, int b) -> int { return a * b; }},
    };

   public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> operators;

        int v = 0;
        for (char c : expression) {
            if (isdigit(c)) {
                v = v * 10 + c - '0';
            } else {
                operators.push_back(c);
                nums.push_back(v);
                v = 0;
            }
        }
        nums.push_back(v);

        unordered_map<int, unordered_map<int, vector<int>>> cache;
        function<vector<int>(int, int)> process = [&](int l,
                                                      int r) -> vector<int> {
            if (l == r) return {nums[l]};

            if (cache[l].count(r)) return cache[l][r];

            vector<int> result;
            for (int i = l; i < r; ++i) {
                for (int a : process(l, i)) {
                    for (int b : process(i + 1, r)) {
                        result.push_back(ops[operators[i]](a, b));
                    }
                }
            }

            return cache[l][r] = result;
        };

        return process(0, nums.size() - 1);
    }
};

class Solution {
    unordered_map<char, function<int(int, int)>> ops = {
        {'+', [](int a, int b) -> int { return a + b; }},
        {'-', [](int a, int b) -> int { return a - b; }},
        {'*', [](int a, int b) -> int { return a * b; }},
    };

   public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> operators;

        int v = 0;
        for (char c : expression) {
            if (isdigit(c)) {
                v = v * 10 + c - '0';
            } else {
                operators.push_back(c);
                nums.push_back(v);
                v = 0;
            }
        }
        nums.push_back(v);

        unordered_map<int, unordered_map<int, vector<int>>> cache;
        function<void(int, int)> process = [&](int l, int r) -> void {
            if (cache[l].count(r)) return;
            if (l == r) {
                cache[l][r] = {nums[l]};
                return;
            }

            vector<int> result;
            for (int i = l; i < r; ++i) {
                process(l, i);
                process(i + 1, r);
                for (int a : cache[l][i]) {
                    for (int b : cache[i + 1][r]) {
                        result.push_back(ops[operators[i]](a, b));
                    }
                }
            }
            cache[l][r] = result;
            return;
        };

        process(0, nums.size() - 1);
        return cache[0][nums.size() - 1];
    }
};
