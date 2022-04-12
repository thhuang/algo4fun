class Solution {
   public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int w = r - l;
            int h = min(height[l], height[r]);
            result = max(result, w * h);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }
};
