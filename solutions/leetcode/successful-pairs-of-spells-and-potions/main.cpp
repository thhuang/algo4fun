class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());

        int n = spells.size();
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            auto j = lower_bound(potions.begin(), potions.end(), success,
                                 [&](int v, long long t) -> bool {
                                     return (long long)v * spells[i] < success;
                                 }) -
                     potions.begin();
            result[i] = potions.size() - j;
        }

        return result;
    }
};
