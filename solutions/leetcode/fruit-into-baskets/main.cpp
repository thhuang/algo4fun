class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int result = 0;
        unordered_map<int, int> types;
        for (int l = 0, r = 0; r < fruits.size(); ++r) {
            ++types[fruits[r]];
            while (types.size() > 2) {
                int t = fruits[l++];
                if (--types[t] == 0) types.erase(t);
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
