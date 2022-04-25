class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> length(nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        int max_length = 0;
        int p = 0;

        for (int r = 0; r < nums.size(); ++r) {
            for (int l = 0; l < r; ++l) {
                if (nums[r] % nums[l] != 0) continue;
                if (length[l] + 1 <= length[r]) continue;
                length[r] = length[l] + 1;
                prev[r] = l;
            }

            if (length[r] <= max_length) continue;
            max_length = length[r];
            p = r;
        }

        vector<int> result;
        while (true) {
            result.push_back(nums[p]);
            if (prev[p] == -1) break;
            p = prev[p];
        }

        return result;
    }
};
