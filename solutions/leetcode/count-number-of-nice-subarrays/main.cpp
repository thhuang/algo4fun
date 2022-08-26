class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odd;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) odd.push_back(i);
        }

        int result = 0;
        for (int l = 0; l + k - 1 < odd.size(); ++l) {
            int r = l + k - 1;

            int a = -1;
            if (l - 1 >= 0) a = odd[l - 1];

            int b = n;
            if (r + 1 < odd.size()) b = odd[r + 1];

            result += (odd[l] - a) * (b - odd[r]);
        }

        return result;
    }
};
