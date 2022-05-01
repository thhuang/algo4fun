class Solution {
   public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i] % p == 0 ? 1 : 0;
        }

        unordered_set<string> subarrays;
        int count = 0;
        int sum = 0;
        for (int l = 0, r = 0; l < n; ++l) {
            while (r < n && sum < k) {
                sum += arr[r++];
            }
            while (r < n && sum == k && arr[r] == 0) {
                sum += arr[r++];
            }

            string s;
            for (int i = l; i < r; ++i) {
                s += to_string(nums[i]);
                s += ":";
                subarrays.insert(s);
            }
            sum -= arr[l];
        }

        return subarrays.size();
    }
};
