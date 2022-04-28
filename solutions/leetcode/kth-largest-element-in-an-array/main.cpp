class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int target_index = nums.size() - k;

        auto partition = [&nums](int l, int r, int p) -> int {
            int pivot = nums[p];
            swap(nums[p], nums[r]);
            int pl = l, pr = r - 1;
            int i = l;
            while (pl <= pr) {
                if (nums[i] < pivot) {
                    swap(nums[i++], nums[pl++]);
                } else {  // nums[i] >= pivot
                    swap(nums[i], nums[pr--]);
                }
            }
            swap(nums[pl], nums[r]);
            return pl;
        };

        int l = 0, r = nums.size() - 1;
        while (true) {
            if (l == r) return nums[l];

            int p = l + rand() % (r - l + 1);
            p = partition(l, r, p);

            if (p == target_index) {
                return nums[p];
            } else if (p < target_index) {
                l = p + 1;
            } else {  // p > target_index
                r = p - 1;
            }
        }

        return 0;
    }
};
