class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> val_occur;
        for (int v : arr) ++val_occur[v];
        unordered_set<int> occurs;
        for (auto [v, n] : val_occur) {
            if (occurs.count(n) > 0) return false;
            occurs.insert(n);
        }
        return true;
    }
};
