class Solution {
   public:
    int thirdMax(vector<int>& nums) {
        vector<int> result;
        for (int v : nums) {
            if (find(result.begin(), result.end(), v) != result.end()) {
                continue;
            }
            result.push_back(v);
            sort(result.begin(), result.end(), greater<>());
            if (result.size() > 3) {
                result.pop_back();
            }
        }
        return result[2 % result.size()];
    }
};
