class Solution {
   public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);

        if (n <= k * 2) return result;

        long long sum = accumulate(nums.begin(), nums.begin() + k * 2, 0LL);
        for (int i = k * 2; i < n; ++i) {
            sum += nums[i];
            result[i - k] = sum / (k * 2 + 1);
            sum -= nums[i - k * 2];
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int window = k * 2 + 1;

        vector<int> result(n, -1);
        for (long long r = 0, i = r - k, l = i - k, sum = 0; r < n;
             ++l, ++i, ++r) {
            sum += nums[r];
            if (l < 0) continue;
            result[i] = sum / window;
            sum -= nums[l];
        }

        return result;
    }
};
