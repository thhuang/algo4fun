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

class Solution {
   public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1,
                                     vector<vector<int>>& encoded2) {
        vector<vector<int>> result;

        int i1 = 0, c1 = 0;
        int i2 = 0, c2 = 0;
        while (i1 < encoded1.size() && i2 < encoded2.size()) {
            c1 = c1 ? c1 : encoded1[i1][1];
            c2 = c2 ? c2 : encoded2[i2][1];

            int value = encoded1[i1][0] * encoded2[i2][0];
            int count = min(c1, c2);

            if (result.empty() || result.back()[0] != value) {
                result.push_back({value, count});
            } else {
                result.back()[1] += count;
            }

            if ((c1 -= count) == 0) ++i1;
            if ((c2 -= count) == 0) ++i2;
        }

        return result;
    }
};
