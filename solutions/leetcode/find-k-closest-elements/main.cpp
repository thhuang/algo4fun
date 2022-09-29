class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (i == n || (i > 0 && abs(arr[i - 1] - x) < abs(arr[i] - x))) --i;

        int l = i, r = i;
        while (r - l - 1 < k) {
            if (l < 0) {
                ++r;
            } else if (r == n) {
                --l;
            } else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                --l;
            } else {
                ++r;
            }
        }

        return {arr.begin() + l + 1, arr.begin() + r};
    }
};
