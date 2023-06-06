class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> cnt;
        for (int v : nums) {
            if (cnt[v] == 0) {
                ++cnt[k - v];
            } else {
                --cnt[v];
                ++result;
            }
        }
        return result;
    }
};
