class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> result;

        function<void(int)> search = [&](int i) -> void {
            if (i == n) {
                result.push_back(nums);
                return;
            }

            for (int j = i; j < n; ++j) {
                swap(nums[i], nums[j]);
                search(i + 1);
                swap(nums[i], nums[j]);
            }
        };

        search(0);

        return result;
    }
};
