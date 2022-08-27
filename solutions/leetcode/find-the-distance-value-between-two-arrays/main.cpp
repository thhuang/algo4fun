class Solution {
   public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int result = 0;
        for (int v : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), v);
            if (it != arr2.end() && abs(v - *it) <= d) continue;
            if (it != arr2.begin() && abs(v - *prev(it) <= d)) continue;
            ++result;
        }

        return result;
    }
};
