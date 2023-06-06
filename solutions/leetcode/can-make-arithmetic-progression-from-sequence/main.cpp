class Solution {
   public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] != d) return false;
        }
        return true;
    }
};

class Solution {
   public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        int mn = *min_element(arr.begin(), arr.end());
        int n = arr.size();

        if ((mx - mn) % (n - 1) != 0) return false;
        int d = (mx - mn) / (n - 1);

        if (d == 0) return true;

        vector<bool> vis(n, false);
        for (int v : arr) {
            int dv = v - mn;
            if (dv % d != 0) return false;
            if (vis[dv / d]) return false;
            vis[dv / d] = true;
        }

        return true;
    }
};
