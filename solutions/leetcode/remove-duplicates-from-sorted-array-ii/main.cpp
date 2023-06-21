class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        for (int l = 0; l < n;) {
            int v = nums[p++] = nums[l];

            int r = l + 1;
            while (r < n && nums[r] == v) {
                if (r - l < 2) nums[p++] = v;
                ++r;
            }

            l = r;
        }

        return p;
    }
};

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int p = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                if (++cnt >= 2) continue;
                nums[p++] = nums[i];
            } else {
                cnt = 0;
                nums[p++] = nums[i];
            }
        }
        return p;
    }
};
