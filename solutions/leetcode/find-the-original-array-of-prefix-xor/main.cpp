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

class Solution {
   public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        vector<int> rresult;

        for (int i = n - 1; i > 0; --i) {
            rresult.push_back(pref[i] ^ pref[i - 1]);
        }
        rresult.push_back(pref[0]);

        return {rresult.rbegin(), rresult.rend()};
    }
};
