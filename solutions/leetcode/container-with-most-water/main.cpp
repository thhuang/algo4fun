class Solution {
   public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int lh = height[l], rh = height[r];
            result = max(result, min(lh, rh) * (r - l));
            lh < rh ? ++l : --r;
        }
        return result;
    }
};
