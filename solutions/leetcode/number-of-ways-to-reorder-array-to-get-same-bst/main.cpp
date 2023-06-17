class Solution {
    const int mod = 1e9 + 7;

   public:
    int numOfWays(vector<int>& nums) {
        vector<vector<int>> table = {{1}, {1, 1}};
        for (int i = 2; i <= nums.size(); ++i) {
            table.push_back(vector<int>(i + 1));
            for (int j = 0; j < i + 1; ++j) {
                int a = j == 0 ? 0 : table[i - 1][j - 1];
                int b = j == i ? 0 : table[i - 1][j];
                table[i][j] = ((long long)a + b) % mod;
            }
        }

        return dfs(nums, table) - 1;
    }

    int dfs(vector<int>& nums, vector<vector<int>>& table) {
        if (nums.size() <= 2) return 1;

        vector<int> left, right;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long l = dfs(left, table);
        long long r = dfs(right, table);
        return (long long)table[n - 1][left.size()] * (l * r % mod) % mod;
    }
};
