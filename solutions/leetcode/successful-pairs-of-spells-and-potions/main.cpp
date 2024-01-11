class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());

        vector<int> result;

        for (int s : spells) {
            int i = lower_bound(potions.begin(), potions.end(), success,
                                [s](int p, long long t) -> bool {
                                    return (long long)s * p < (long long)t;
                                }) -
                    potions.begin();
            result.push_back(potions.size() - i);
        }

        return result;
    }
};
