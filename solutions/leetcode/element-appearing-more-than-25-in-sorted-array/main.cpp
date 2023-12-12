class Solution {
   public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> numFreq;
        for (int v : arr) {
            ++numFreq[v];
        }
        for (auto [v, f] : numFreq) {
            if (f > arr.size() / 4) {
                return v;
            }
        }
        return -1;
    }
};
