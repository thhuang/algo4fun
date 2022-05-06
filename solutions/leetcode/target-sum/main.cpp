class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int v : nums) total += v;

        if (target < -total || total < target) return 0;

        unordered_map<int, int> sum_ways = {{0, 1}};
        for (int v : nums) {
            unordered_map<int, int> new_sum_ways;
            for (auto [s, w] : sum_ways) {
                new_sum_ways[s + v] += sum_ways[s];
                new_sum_ways[s - v] += sum_ways[s];
            }
            sum_ways = move(new_sum_ways);
        }

        return sum_ways[target];
    }
};
