class Solution {
   public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> left(n + 1, 0);
        vector<long long> right(n + 1, 0);

        for (long long i = 0, sum = 0; i < n; ++i) {
            sum += nums[i];
            left[i] = sum / (i + 1);
        }
        for (long long i = 0, sum = 0; i < n; ++i) {
            int j = n - 1 - i;
            sum += nums[j];
            right[j] = sum / (i + 1);
        }

        int result = -1;
        long long dist = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            long long v = abs(left[i] - right[i + 1]);
            if (v < dist) result = i, dist = v;
        }

        return result;
    }
};
