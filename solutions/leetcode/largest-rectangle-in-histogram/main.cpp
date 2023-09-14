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

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rect_index;

        auto new_height_or_reached_end = [&](int i) -> bool {
            return i == n || heights[rect_index.back()] >= heights[i];
        };

        int result = 0;
        for (int i = 0; i <= n; ++i) {
            while (!rect_index.empty() && new_height_or_reached_end(i)) {
                int h = heights[rect_index.back()];
                rect_index.pop_back();

                int w = i;
                if (!rect_index.empty()) w -= rect_index.back() + 1;

                result = max(result, h * w);
            }
            rect_index.push_back(i);
        }

        return result;
    }
};

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);

        int n = heights.size();
        vector<pair<int, int>> asc;  // {index, height}

        int result = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (!asc.empty() && asc.back().second > heights[i]) {
                j = asc.back().first;
                result = max(result, (i - j) * asc.back().second);
                asc.pop_back();
            }
            asc.push_back({j, heights[i]});
        }

        return result;
    }
};

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);

        int n = heights.size();
        vector<array<int, 2>> inc = {{-1, 0}};  // {index, height}

        int result = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (inc.back()[1] > heights[i]) {
                auto [l, h] = inc.back();
                inc.pop_back();
                result = max(result, (i - l) * h);
                j = l;
            }
            inc.push_back({j, heights[i]});
        }

        return result;
    }
};
