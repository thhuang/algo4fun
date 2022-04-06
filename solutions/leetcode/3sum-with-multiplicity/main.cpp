class Solution {
    const int mod = 1e9 + 7;

   public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long result = 0;

        unordered_map<int, int> num_count;
        vector<int> nums;
        for (int v : arr) {
            if (++num_count[v] == 1) nums.push_back(v);
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int j = i, k = nums.size() - 1;
            while (j <= k) {
                int v = nums[i] + nums[j] + nums[k];
                if (v < target) {
                    ++j;
                    continue;
                }
                if (v > target) {
                    --k;
                    continue;
                }

                if (i == j && j == k) {
                    if (long long n = num_count[nums[i]]; n >= 3) {
                        long long count = (n * (n - 1) * (n - 2) / 6) % mod;
                        result = (result + count) % mod;
                    }
                } else if (i == j) {
                    if (long long n = num_count[nums[i]]; n >= 2) {
                        long long count =
                            (n * (n - 1) / 2 * num_count[nums[k]]) % mod;
                        result = (result + count) % mod;
                    }
                } else if (j == k) {
                    if (long long n = num_count[nums[j]]; n >= 2) {
                        long long count =
                            (n * (n - 1) / 2 * num_count[nums[i]]) % mod;
                        result = (result + count) % mod;
                    }
                } else if (i != j && j != k) {
                    long long count = (num_count[nums[i]] * num_count[nums[j]] *
                                       num_count[nums[k]]) %
                                      mod;
                    result = (result + count) % mod;
                }
                ++j;
            }
        }

        return result;
    }
};
