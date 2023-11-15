class Solution {
   public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int result = 1;
        for (int v : arr) {
            if (result < v) {
                ++result;
            }
        }
        return result;
    }
};
