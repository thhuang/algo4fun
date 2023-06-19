class Solution {
   public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        for (int i = 0, h = 0; i < gain.size(); ++i)
            result = max(result, h += gain[i]);
        return result;
    }
};
