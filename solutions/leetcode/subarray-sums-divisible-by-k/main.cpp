class Solution {
   public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count = {{0, 1}};
        int result = 0;
        int m = 0;
        for (int v : nums) {
            m = (m + v) % k;
            m = (m + k) % k;
            result += count[m];
            ++count[m];
        }
        return result;
    }
};
