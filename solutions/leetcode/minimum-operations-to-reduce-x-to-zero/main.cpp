class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int v : nums) sum += v;
        if (sum == x) return n;
        if (sum < x) return -1;

        unordered_map<int, int> sum_index;
        sum_index[0] = -1;

        int target = sum - x;
        int result = numeric_limits<int>::max();
        for (int i = 0, s = 0; i < n; ++i) {
            s += nums[i];
            if (auto it = sum_index.find(s - target); it != sum_index.end()) {
                result = min(result, n - i + it->second);
            }
            if (sum_index.count(s) == 0) {
                sum_index[s] = i;
            }
        }

        return result > n ? -1 : result;
    }
};
