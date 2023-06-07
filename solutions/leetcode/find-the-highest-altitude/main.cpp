class Solution {
   public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int h = 0;
        for (int v : gain) {
            result = max(result, h += v);
        }
        return result;
    }
};
