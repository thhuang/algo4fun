class Solution {
   public:
    int minDistance(int height, int width, vector<int>& tree,
                    vector<int>& squirrel, vector<vector<int>>& nuts) {
        int result = numeric_limits<int>::max();
        for (const auto& nut : nuts) {
            int diff = distance(nut[0], nut[1], squirrel[0], squirrel[1]) -
                       distance(nut[0], nut[1], tree[0], tree[1]);
            result = min(result, diff);
        }
        for (const auto& nut : nuts) {
            result += distance(nut[0], nut[1], tree[0], tree[1]) * 2;
        }
        return result;
    }
    int distance(int i1, int j1, int i2, int j2) {
        return abs(i1 - i2) + abs(j1 - j2);
    }
};
