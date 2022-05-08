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

class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefix_sum(n);
        for (int i = 0, sum = 0; i < n; ++i) {
            prefix_sum[i] = sum += arr[i];
        }

        int result = 0;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; r += 2) {
                int s = prefix_sum[r];
                if (l > 0) s -= prefix_sum[l - 1];
                result += s;
            }
        }

        return result;
    }
};
