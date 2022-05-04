class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> target_count;
        for (int v : nums) {
            if (v >= k) continue;
            if (target_count[v]) {
                --target_count[v];
                ++count;
            } else {
                ++target_count[k - v];
            }
        }
        return count;
    }
};
