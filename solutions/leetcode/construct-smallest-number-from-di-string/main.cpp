class Solution {
   public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<int> nums(n + 1);
        iota(nums.begin(), nums.end(), 1);
        do {
            int valid = true;
            for (int i = 0; i < n; ++i) {
                if (pattern[i] == 'I' && nums[i] > nums[i + 1] ||
                    pattern[i] == 'D' && nums[i] < nums[i + 1]) {
                    valid = false;
                    break;
                }
            }
            if (valid) break;
        } while (next_permutation(nums.begin(), nums.end()));

        string result;
        for (int v : nums) result += to_string(v);
        return result;
    }
};
