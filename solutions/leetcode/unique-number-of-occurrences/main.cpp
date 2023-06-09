class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrence;
        for (int v : arr) ++occurrence[v];
        unordered_set<int> seen;
        for (auto [_, v] : occurrence) {
            if (seen.count(v) != 0) return false;
            seen.insert(v);
        }
        return true;
    }
};
