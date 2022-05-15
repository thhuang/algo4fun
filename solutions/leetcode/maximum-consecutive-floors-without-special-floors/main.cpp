class Solution {
   public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        special.push_back(top + 1);
        int result = special.front() - bottom;
        for (int i = 1; i < special.size(); ++i) {
            result = max(result, special[i] - special[i - 1] - 1);
        }
        return result;
    }
};
