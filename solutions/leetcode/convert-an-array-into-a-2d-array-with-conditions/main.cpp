class Solution {
   public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> numFreq;
        vector<vector<int>> result;
        for (int v : nums) {
            int row = numFreq[v]++;
            if (result.size() == row) {
                result.push_back({});
            }
            result[row].push_back(v);
        }
        return result;
    }
};
