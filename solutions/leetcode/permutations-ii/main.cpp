class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        function<void(int)> search = [&](int i) -> void {
            if (i == nums.size()) {
                result.push_back(nums);
                return;
            }
            unordered_set<int> seen;
            for (int j = i; j < nums.size(); ++j) {
                if (seen.count(nums[j]) > 0) continue;
                seen.insert(nums[j]);
                swap(nums[j], nums[i]);
                search(i + 1);
                swap(nums[j], nums[i]);
            }
        };
        search(0);
        return result;
    }
};
