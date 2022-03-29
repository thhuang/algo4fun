class Solution {
   public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (size(arr) < 3) return true;

        sort(begin(arr), end(arr));
        int d = arr[1] - arr[0];
        for (int i = 0; i < size(arr) - 1; ++i) {
            if (arr[i + 1] - arr[i] != d) return false;
        }
        return true;
    }
};
