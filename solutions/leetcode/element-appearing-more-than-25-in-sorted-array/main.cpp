class Solution {
   public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> numFreq;
        for (int v : arr) {
            ++numFreq[v];
        }
        for (auto [v, f] : numFreq) {
            if (f > arr.size() / 4) {
                return v;
            }
        }
        return -1;
    }
};

class Solution {
   public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int p = arr.front() - 1;
        int cnt = 0;
        for (int v : arr) {
            if (v == p) {
                ++cnt;
                if (cnt > n / 4) return v;
            } else {
                p = v;
                cnt = 1;
            }
        }
        return p;
    }
};

class Solution {
   public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        auto check = [&](int v) -> bool {
            auto l = lower_bound(arr.begin(), arr.end(), v);
            auto r = upper_bound(arr.begin(), arr.end(), v);
            return (r - l) > arr.size() / 4;
        };
        if (int v = arr[n / 4]; check(v)) return v;
        if (int v = arr[n / 2]; check(v)) return v;
        return arr[n * 3 / 4];
    }
};
