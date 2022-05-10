class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> water_height(n);
        for (int i = 0, h = 0; i < n; ++i) {
            h = max(h, height[i]);
            water_height[i] = h;
        }

        int sum = 0;
        for (int i = n - 1, h = 0; ~i; --i) {
            h = max(h, height[i]);
            water_height[i] = min(water_height[i], h);
            sum += water_height[i] - height[i];
        }

        return sum;
    }
};

class Solution {
   public:
    int trap(vector<int>& height) {
        int sum = 0;

        int m = 0;
        for (int l = 0, r = 0; r < size(height); ++r) {
            int hl = height[l];
            while (l < r && height[l] <= height[r]) {
                sum += hl - height[l];
                ++l;
            }
            m = l;
        }

        for (int l = size(height) - 1, r = size(height) - 1; m <= l; --l) {
            int hr = height[r];
            while (l < r && height[l] >= height[r]) {
                sum += hr - height[r];
                --r;
            }
        }

        return sum;
    }
};
