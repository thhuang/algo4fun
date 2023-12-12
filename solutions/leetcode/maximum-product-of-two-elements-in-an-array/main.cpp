class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 0;
        int mx1i = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            if (v > mx1) {
                mx1 = v;
                mx1i = i;
            }
        }

        int mx2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == mx1i) continue;
            int v = nums[i];
            mx2 = max(mx2, v);
        }

        return (mx1 - 1) * (mx2 - 1);
    }
};
