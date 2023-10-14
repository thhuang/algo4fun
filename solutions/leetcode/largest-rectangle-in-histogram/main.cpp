class Solution {
    struct HeightIndex {
        int h, i;
    };

   public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;

        heights.push_back(0);

        stack<HeightIndex> incr;
        for (int i = 0; i < heights.size(); ++i) {
            int l = i;
            int h = heights[i];
            while (!incr.empty() && incr.top().h > h) {
                l = incr.top().i;
                result = max(result, (i - l) * incr.top().h);
                incr.pop();
            }
            incr.push({h, l});
        }

        heights.pop_back();

        return result;
    }
};
