class Solution {
   public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int result = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (result < arr[i]) {
                ++result;
            }
        }
        return result;
    }
};

class Solution {
   public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n + 1, 0);
        for (int v : arr) {
            ++freq[min(v, n)];
        }

        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result = min(i, result + freq[i]);
        }

        return result;
    }
};
