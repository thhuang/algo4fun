class Solution {
   public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> numFreq;
        for (int v : nums) ++numFreq[v];
        int result = 0;
        for (auto [_, v] : numFreq) {
            if (v == 1) continue;
            result += (v - 1) * v / 2;
        }
        return result;
    }
};
