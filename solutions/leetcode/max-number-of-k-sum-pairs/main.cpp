class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> numCount;
        for (int v : nums) {
            if (numCount[v] > 0) {
                --numCount[v];
                ++result;
            } else {
                ++numCount[k - v];
            }
        }
        return result;
    }
};
