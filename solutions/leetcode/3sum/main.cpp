class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        unordered_map<int, int> num_count;
        vector<int> dedup_nums;
        for (int v : nums) {
            if (++num_count[v] == 1) dedup_nums.push_back(v);
        }

        sort(dedup_nums.begin(), dedup_nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < dedup_nums.size(); ++i) {
            int l = i, r = dedup_nums.size() - 1;
            while (l <= r) {
                int a = dedup_nums[i];
                int b = dedup_nums[l];
                int c = dedup_nums[r];

                int sum = a + b + c;
                if (sum < 0) {
                    ++l;
                    continue;
                } else if (sum > 0) {
                    --r;
                    continue;
                }

                if ((i == l && l == r && num_count[a] >= 3) ||
                    (i == l && l != r && num_count[a] >= 2) ||
                    (i != l && l == r && num_count[b] >= 2) ||
                    (i != l && l != r)) {
                    result.push_back({a, b, c});
                }
                ++l;
            }
        }

        return result;
    }
};
