class Solution {
   public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> left(n), right(n);
        vector<int> desc;

        for (int i = 0; i < n; ++i) {
            while (!desc.empty() && nums[desc.back()] > nums[i]) {
                right[desc.back()] = i - 1;
                desc.pop_back();
            }
            desc.push_back(i);
        }
        while (!desc.empty()) {
            right[desc.back()] = n - 1;
            desc.pop_back();
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!desc.empty() && nums[desc.back()] > nums[i]) {
                left[desc.back()] = i + 1;
                desc.pop_back();
            }
            desc.push_back(i);
        }
        while (!desc.empty()) {
            left[desc.back()] = 0;
            desc.pop_back();
        }

        int result = 0;

        for (int i = 0; i < n; ++i) {
            int l = left[i];
            int r = right[i];
            if (l <= k && k <= r) {
                result = max(result, nums[i] * (r - l + 1));
            }
        }

        return result;
    }
};

class Solution {
   public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int result = nums[k];

        int l = k, r = k, mn = nums[k];
        while (0 < l || r < n - 1) {
            if (l == 0) {
                mn = min(mn, nums[++r]);
            } else if (r == n - 1) {
                mn = min(mn, nums[--l]);
            } else if (nums[l - 1] > nums[r + 1]) {
                mn = min(mn, nums[--l]);
            } else {  // nums[l - 1] <= nums[r + 1]
                mn = min(mn, nums[++r]);
            }
            result = max(result, mn * (r - l + 1));
        }

        return result;
    }
};
