class Solution {
    const int mod = 1e9 + 7;

   public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> inc;

        vector<int> right(n);
        for (int i = 0; i < n; ++i) {
            while (!inc.empty() && arr[inc.back()] > arr[i]) {
                right[inc.back()] = i;
                inc.pop_back();
            }
            inc.push_back(i);
        }
        for (int i : inc) right[i] = n;
        inc.clear();

        vector<int> left(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!inc.empty() && arr[inc.back()] >= arr[i]) {
                left[inc.back()] = i;
                inc.pop_back();
            }
            inc.push_back(i);
        }
        for (int i : inc) left[i] = -1;

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result += 1LL * arr[i] * (i - left[i]) * (right[i] - i);
            result %= mod;
        }

        return result;
    }
};
