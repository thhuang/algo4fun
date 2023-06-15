class Solution {
   public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower,
                                          int upper) {
        if (nums.empty()) return {{lower, upper}};

        vector<vector<int>> result;
        int l = lower;
        for (int v : nums) {
            if (l < v) {
                result.push_back({l, v - 1});
            }
            l = v + 1;
        }
        cout << l << '\n';
        if (l <= upper) result.push_back({l, upper});

        return result;
    }
};
