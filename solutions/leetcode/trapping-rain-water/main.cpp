class Solution {
   public:
    int trap(vector<int>& height) {
        vector<int> water(size(height), 0);

        int h = 0;
        for (int i = 0; i < size(height); ++i) {
            h = max(h, height[i]);
            water[i] = h;
        }

        int sum = 0;
        h = 0;
        for (int i = size(height) - 1; ~i; --i) {
            h = max(h, height[i]);
            sum += min(h, water[i]) - height[i];
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
