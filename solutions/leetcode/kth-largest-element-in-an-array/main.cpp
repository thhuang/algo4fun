class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int t = n - k;

        auto partition = [&](int l, int r, int i) -> int {
            swap(nums[i], nums[r]);
            int p = l;
            for (int j = l; j < r; ++j) {
                if (nums[j] < nums[r]) {
                    swap(nums[j], nums[p++]);
                }
            }
            swap(nums[p], nums[r]);
            return p;
        };

        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            m = partition(l, r, m);
            if (m <= t) {
                l = m + 1;
            } else {  // m > t
                r = m - 1;
            }
        }

        return nums[r];
    }
};

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        function<int(int, int)> partition = [&](int l, int r) -> int {
            for (int i = l; i < r; ++i)
                if (nums[i] < nums[r]) swap(nums[i], nums[l++]);
            swap(nums[l], nums[r]);
            return l;
        };

        int n = nums.size();
        int t = n - k;
        int l = 0, r = n - 1;
        while (l <= r) {
            int p = partition(l, r);
            if (p < t) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }

        return nums[l];
    }
};

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        auto partition = [&](int l, int r, int t) -> int {
            swap(nums[t], nums[r]);

            int p = l, a = l, b = r - 1;
            while (p <= b) {
                if (nums[p] > nums[r]) {
                    swap(nums[p++], nums[a++]);
                } else {
                    swap(nums[p], nums[b--]);
                }
            }

            swap(nums[p], nums[r]);

            return p;
        };

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int i = partition(l, r, m);
            if (i < k - 1) {
                l = i + 1;
            } else {
                r = i - 1;
            }
        }

        return nums[l];
    }
};
