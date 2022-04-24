class Solution {
   public:
    vector<int> countRectangles(vector<vector<int>>& rectangles,
                                vector<vector<int>>& points) {
        int n = rectangles.size();

        vector<vector<int>> hl(101);
        for (const auto& r : rectangles) hl[r[1]].push_back(r[0]);
        for (auto& l : hl) sort(l.begin(), l.end());

        vector<int> result;
        for (const auto& p : points) {
            int x = p[0], y = p[1];
            int count = 0;
            for (int h = y; h < hl.size(); ++h) {
                int d =
                    lower_bound(hl[h].begin(), hl[h].end(), x) - hl[h].begin();
                count += hl[h].size() - d;
            }
            result.push_back(count);
        }

        return result;
    }
};
