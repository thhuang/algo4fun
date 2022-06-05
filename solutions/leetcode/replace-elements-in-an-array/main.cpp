class Solution {
   public:
    vector<int> arrayChange(vector<int>& nums,
                            vector<vector<int>>& operations) {
        unordered_map<int, int> num_index;
        for (int i = 0; i < nums.size(); ++i) num_index[nums[i]] = i;

        for (const auto& op : operations) {
            int from = op[0];
            int to = op[1];
            int i = num_index[from];
            num_index.erase(from);
            num_index[to] = i;
        }

        for (const auto [v, i] : num_index) nums[i] = v;

        return nums;
    }
};
