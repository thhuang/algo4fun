class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int result = 0;
        vector<array<int, 2>> height_index;
        for (int i = 0; i < n; ++i) {
            int h = heights[i];
            if (height_index.empty() || h > height_index.back()[0]) {
                height_index.push_back({h, i});
                continue;
            }

            int j = i;
            while (!height_index.empty() && h <= height_index.back()[0]) {
                auto [lh, li] = height_index.back();
                height_index.pop_back();
                result = max(result, lh * (i - li));
                j = li;
            }
            height_index.push_back({h, j});
        }

        while (!height_index.empty()) {
            auto [h, i] = height_index.back();
            height_index.pop_back();
            result = max(result, h * (n - i));
        }

        return result;
    }
};
