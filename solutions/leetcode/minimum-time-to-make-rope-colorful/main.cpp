class Solution {
   public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0;

        int n = colors.size();
        for (int l = 0; l < n; ++l) {
            int sum = 0;
            int mx = neededTime[l];
            int r = l;
            while (r < n && colors[l] == colors[r]) {
                mx = max(mx, neededTime[r]);
                sum += neededTime[r];
                ++r;
            }
            --r;

            if (l < r) {
                result += sum - mx;
            }

            l = r;
        }

        return result;
    }
};
