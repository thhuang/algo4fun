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
        int n = height.size();
        int result = 0;

        int l = 0, r = 0, m = 0;
        while (true) {
            int water = 0;
            while (r < n && height[l] >= height[r]) {
                water += height[l] - height[r];
                ++r;
            }
            if (r == n) {
                m = l;
                break;
            }

            result += water;
            l = r;
        }

        l = n - 1, r = n - 1;
        while (r > m) {
            int water = 0;
            while (l >= m && height[l] <= height[r]) {
                water += height[r] - height[l];
                --l;
            }
            result += water;
            r = l;
        }

        return result;
    }
};

class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;

        int m = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            int h = height[l];
            while (l < r && height[r] >= height[l]) {
                result += h - height[l++];
            }
            m = l;
        }

        for (int l = n - 1, r = n - 1; l >= m; --l) {
            int h = height[r];
            while (l < r && height[l] >= height[r]) {
                result += h - height[r--];
            }
        }

        return result;
    }
};

class Solution {
   public:
    int trap(vector<int>& height) {
        int result = 0;
        for (auto l = height.begin(), r = height.begin(); r < height.end(); ++r) {
            if (*l >= *r) continue;
            int h = *l;
            while (l < r) result += h - *l++;
        }
        for (auto l = height.rbegin(), r = height.rbegin(); r < height.rend(); ++r) {
            if (*l > *r) continue;
            int h = *l;
            while (l < r) result += h - *l++;
        }
        return result;
    }
};
