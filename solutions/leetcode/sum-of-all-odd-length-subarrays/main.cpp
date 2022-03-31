class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int length = 1; length <= size(arr); length += 2) {
            for (int i = 0; i <= size(arr) - length; ++i) {
                for (int j = i; j < i + length; ++j) {
                    ans += arr[j];
                }
            }
        }
        return ans;
    }
};
