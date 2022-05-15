class Solution {
   public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int v : candidates) {
                if ((v >> i) & 1) ++count;
            }
            result = max(result, count);
        }
        return result;
    }
};
