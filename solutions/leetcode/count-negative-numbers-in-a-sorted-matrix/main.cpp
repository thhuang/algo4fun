class Solution {
    int firstNegativeIndex(vector<int>& nums) {
        int l = -1, r = nums.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (nums[m] >= 0) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }

   public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (vector<int>& nums : grid) {
            int i = firstNegativeIndex(nums);
            result += nums.size() - i;
        }
        return result;
    }
};

class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        int result = 0;
        for (int i = 0, j = n - 1; i < m; ++i) {
            while (j >= 0 && grid[i][j] < 0) --j;
            result += n - j - 1;
        }

        return result;
    }
};
