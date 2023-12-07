class Solution {
   public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;

        unordered_map<int, int> prefix = {};

        for (int t : time) {
            int v = t % 60;
            result += prefix[v];
            ++prefix[(60 - v) % 60];
        }

        return result;
    }
};
