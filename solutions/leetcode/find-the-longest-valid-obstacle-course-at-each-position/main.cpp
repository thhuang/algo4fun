class Solution {
   public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> result;
        vector<int> asc;
        for (int v : obstacles) {
            int i = upper_bound(asc.begin(), asc.end(), v) - asc.begin();
            if (i == asc.size()) {
                asc.push_back(v);
            } else {
                asc[i] = v;
            }
            result.push_back(i + 1);
        }
        return result;
    }
};
