class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 2>> length_count(n, {0, 0});
        int max_length = 0;

        for (int r = 0; r < n; ++r) {
            int max_prefix_length = 0;
            int count = 1;
            for (int l = 0; l < r; ++l) {
                if (nums[r] <= nums[l]) continue;
                if (length_count[l][0] < max_prefix_length) continue;
                if (length_count[l][0] == max_prefix_length) {
                    count += length_count[l][1];
                } else {  // length[l][0] > max_prefix_length
                    max_prefix_length = length_count[l][0];
                    count = length_count[l][1];
                }
            }

            int length = max_prefix_length + 1;
            length_count[r] = {length, count};
            max_length = max(max_length, length);
        }

        int result = 0;
        for (const auto& p : length_count) {
            if (p[0] == max_length) result += p[1];
        }

        return result;
    }
};
