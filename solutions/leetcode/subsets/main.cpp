class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        function<void(int)> search = [&](int i) -> void {
            if (i == nums.size()) {
                result.push_back(subset);
                return;
            }
            search(i + 1);
            subset.push_back(nums[i]);
            search(i + 1);
            subset.pop_back();
        };
        search(0);
        return result;
    }
};
