class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (i == n) --i;
        if (i > 0 && abs(arr[i - 1] - x) <= abs(arr[i] - x)) --i;

        int l = i, r = i;
        while (r - l + 1 < k) {
            if (r == n - 1) {
                --l;
            } else if (l == 0) {
                ++r;
            } else if (abs(arr[l - 1] - x) <= abs(arr[r + 1] - x)) {
                --l;
            } else {
                ++r;
            }
        }

        vector<int> result;
        for (int i = l; i <= r; ++i) result.push_back(arr[i]);

        return result;
    }
};
