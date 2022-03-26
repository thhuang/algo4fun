class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int target = image[sr][sc];
        if (target == newColor) return image;

        int n = size(image);
        int m = size(image[0]);
        vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (image[i][j] != target) return;

            image[i][j] = newColor;

            for (auto [di, dj] : directions) dfs(i + di, j + dj);
        };

        dfs(sr, sc);

        return image;
    }
};
