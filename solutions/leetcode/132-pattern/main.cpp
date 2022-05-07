class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        vector<int> min_nums(nums.size());
        for (int i = 0, curr_min = numeric_limits<int>::max(); i < nums.size(); ++i) {
            min_nums[i] = curr_min = min(curr_min, nums[i]);
        }

        vector<int> smallest_seen;
        for (int i = nums.size() - 1; ~i; --i) {
            while (!smallest_seen.empty() && smallest_seen.back() <= min_nums[i]) smallest_seen.pop_back();
            if (nums[i] == min_nums[i]) continue;
            if (!smallest_seen.empty() && nums[i] > smallest_seen.back()) return true;
            smallest_seen.push_back(nums[i]);
        }

        return false;
    }
};
