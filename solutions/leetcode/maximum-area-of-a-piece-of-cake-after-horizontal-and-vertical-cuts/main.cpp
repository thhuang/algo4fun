class Solution {
    const int mod = 1e9 + 7;

   public:
    int maxArea(int h, int w, vector<int>& horizontalCuts,
                vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int max_h = 0;
        for (int i = 0, ph = 0; i < horizontalCuts.size(); ++i) {
            max_h = max(max_h, horizontalCuts[i] - ph);
            ph = horizontalCuts[i];
        }

        int max_w = 0;
        for (int i = 0, pw = 0; i < verticalCuts.size(); ++i) {
            max_w = max(max_w, verticalCuts[i] - pw);
            pw = verticalCuts[i];
        }

        return (long long)max_h * max_w % mod;
    }
};
