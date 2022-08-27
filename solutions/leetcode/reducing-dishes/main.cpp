class Solution {
   public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<>());

        int result = 0;
        for (int i = 0, p = 0, s = 0; i < satisfaction.size(); ++i) {
            p += satisfaction[i];
            result = max(result, s += p);
        }

        return result;
    }
};
