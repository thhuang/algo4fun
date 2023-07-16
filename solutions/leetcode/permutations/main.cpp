class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> result;
        vector<int> curr;

        vector<bool> used(n, false);
        function<void()> dfs = [&]() -> void {
            if (curr.size() == nums.size()) {
                result.push_back(curr);
                return;
            }

            for (int i = 0; i < n; ++i) {
                if (used[i]) continue;

                used[i] = true;
                curr.push_back(nums[i]);
                dfs();
                curr.pop_back();
                used[i] = false;
            }
        };

        dfs();

        return result;
    }
};

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
