class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int v : nums) sum += v;
        if (sum == x) return n;
        if (sum < x) return -1;

        unordered_map<int, int> sum_index;
        sum_index[0] = -1;

        int target = sum - x;
        int result = numeric_limits<int>::max();
        for (int i = 0, s = 0; i < n; ++i) {
            s += nums[i];
            if (auto it = sum_index.find(s - target); it != sum_index.end()) {
                result = min(result, n - i + it->second);
            }
            if (sum_index.count(s) == 0) {
                sum_index[s] = i;
            }
        }

        return result > n ? -1 : result;
    }
};

class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum = 0;
        for (int v : nums) sum += v;

        int target = sum - x;
        int result = numeric_limits<int>::max();
        for (int l = 0, r = 0, s = 0; r < n; ++r) {
            s += nums[r];
            while (l <= r && s > target) s -= nums[l++];
            if (s == target) result = min(result, n - (r - l + 1));
        }

        return result > n ? -1 : result;
    }
};

class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int result = -1;

        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;

        for (int l = 0, r = 0, window = 0; r < n; ++r) {
            window += nums[r];
            while (window > target) {
                window -= nums[l++];
            }
            if (window == target && (result == -1 || n - r + l - 1 < result)) {
                result = n - r + l - 1;
            }
        }

        return result;
    }
};

class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int result = n + 1;

        for (int l = 0, r = 0, window = 0,
                 target = accumulate(nums.begin(), nums.end(), 0) - x;
             r < n; ++r) {
            window += nums[r];
            while (l <= r && window > target) window -= nums[l++];
            if (window == target) result = min(result, n - r + l - 1);
        }

        return result > n ? -1 : result;
    }
};
