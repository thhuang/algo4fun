class Solution {
   public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> result = {0};
        for (int i = 0, v = 0; i < pref.size(); ++i) {
            v ^= result.back();
            result.push_back(v ^ pref[i]);
        }
        return {result.begin() + 1, result.end()};
    }
};
