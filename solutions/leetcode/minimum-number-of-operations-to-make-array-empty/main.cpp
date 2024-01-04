class Solution {
   public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> numFreq;
        for (int v : nums) {
            ++numFreq[v];
        }

        int result = 0;

        for (auto [_, v] : numFreq) {
            if (v == 1) return -1;

            result += v / 3;
            if (v % 3 > 0) ++result;
        }

        return result;
    }
};
