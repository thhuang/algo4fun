class Solution {
   public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> cnt(sideLength * sideLength, 0);
        vector<vector<int>> mat(height, vector<int>(width));
        for (int h = 0; h < height; h += sideLength) {
            for (int w = 0; w < width; w += sideLength) {
                for (int i = 0, k = 0; i < sideLength; ++i) {
                    int ii = h + i;
                    for (int j = 0; j < sideLength; ++j, ++k) {
                        int jj = w + j;
                        if (ii < 0 || height <= ii || jj < 0 || width <= jj) continue;
                        ++cnt[k];
                    }
                }
            }
        }
        sort(cnt.begin(), cnt.end(), greater<>());
        return accumulate(cnt.begin(), cnt.begin() + maxOnes, 0);
    }
};

class Solution {
   public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> cnt(sideLength * sideLength, 0);
        vector<vector<int>> mat(height, vector<int>(width));
        for (int h = 0; h < height; h += sideLength)
            for (int w = 0; w < width; w += sideLength)
                for (int i = h, k = 0; i < h + sideLength; ++i)
                    for (int j = w; j < w + sideLength; ++j, ++k)
                        if (0 <= i && i < height && 0 <= j && j < width)
                            ++cnt[k];
        sort(cnt.begin(), cnt.end(), greater<>());
        return accumulate(cnt.begin(), cnt.begin() + maxOnes, 0);
    }
};
