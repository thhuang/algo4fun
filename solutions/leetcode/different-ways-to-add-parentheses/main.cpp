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
