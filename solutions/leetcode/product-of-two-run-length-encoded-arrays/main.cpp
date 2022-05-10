class Solution {
   public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1,
                                     vector<vector<int>>& encoded2) {
        vector<vector<int>> result;

        while (encoded1.size() && encoded2.size()) {
            auto& v1 = encoded1.back();
            auto& v2 = encoded2.back();
            int value = v1[0] * v2[0];
            int count = min(v1[1], v2[1]);

            if (result.empty() || result.back()[0] != value) {
                result.push_back({value, count});
            } else {
                result.back()[1] += count;
            }

            if ((v1[1] -= count) == 0) encoded1.pop_back();
            if ((v2[1] -= count) == 0) encoded2.pop_back();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
