class Solution {
   public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int result = 0;
        for (int l = 0, r; l < n; l = r) {
            int sum = 0, mx = 0;
            r = l;
            while (r < n && colors[l] == colors[r]) {
                sum += neededTime[r];
                mx = max(mx, neededTime[r]);
                ++r;
            }
            result += sum - mx;
        }
        return result;
    }
};
