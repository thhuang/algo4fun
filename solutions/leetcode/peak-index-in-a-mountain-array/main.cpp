class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        function<int(int, int)> search = [&](int l, int r) -> int {
            if (l == r) return l;
            if (l + 1 == r) return arr[l] > arr[r] ? l : r;

            int m = l + (r - l) / 2;
            if (arr[l] >= arr[m] && arr[m] >= arr[r]) {
                return search(l, m);
            } else if (arr[l] <= arr[m] && arr[m] <= arr[r]) {
                return search(m, r);
            } else {
                int i = search(l, m);
                int j = search(m, r);
                return arr[i] > arr[j] ? i : j;
            }
        };
        return search(0, arr.size() - 1);
    }
};

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        function<int(int, int)> search = [&](int l, int r) -> int {
            while (l < r) {
                int m = l + (r - l) / 2;
                if (arr[m] < arr[m + 1]) {
                    return search(m + 1, r);
                } else if (arr[m] > arr[m + 1]) {
                    return search(l, m);
                } else {
                    int a = search(l, m);
                    int b = search(m + 1, r);
                    return arr[a] > arr[b] ? a : b;
                }
            }
            return l;
        };
        return search(0, arr.size() - 1);
    }
};

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int a = 0 < m ? arr[m - 1] : numeric_limits<int>::min();
            int b = arr[m];
            if (a < b) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};
