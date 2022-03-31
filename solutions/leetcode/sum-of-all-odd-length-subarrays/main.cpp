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

class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = size(arr);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = i + 1;
            int r = n - i;
            ans += arr[i] * ((l * r + 1) / 2);
        }
        return ans;
    }
};
