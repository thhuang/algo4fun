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

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if (n <= k) return arr;

        auto p = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (p == n) --p;
        if (p > 0 && x - arr[p - 1] <= arr[p] - x) --p;

        int l = p, r = p;
        while (r - l + 1 < k) {
            int left = -1e5;
            if (l - 1 >= 0) left = arr[l - 1];

            int right = 1e5;
            if (r + 1 < n) right = arr[r + 1];

            if (x - left <= right - x) {
                --l;
            } else {
                ++r;
            }
        }

        return {arr.begin() + l, arr.begin() + r + 1};
    }
};
