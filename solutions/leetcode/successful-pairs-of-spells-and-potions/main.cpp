class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> result(spells.size());

        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); ++i) {
            int s = spells[i];
            int c = lower_bound(potions.begin(), potions.end(), success,
                                [&](int v, long long t) -> bool {
                                    return (long long)v * s < t;
                                }) - potions.begin();
            result[i] = potions.size() - c;
        }

        return result;
    }
};
