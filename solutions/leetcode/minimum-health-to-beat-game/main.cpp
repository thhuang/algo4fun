class Solution {
   public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int save = min(armor, *max_element(damage.begin(), damage.end()));
        long long result = 1 - save;
        for (int v : damage) result += v;
        return result;
    }
};
