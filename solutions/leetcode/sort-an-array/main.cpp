class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        function<void(int, int)> mergeSort = [&](int l, int r) -> void {
            if (l >= r) return;
            int m = l + (r - l) / 2;

            int la = l, ra = m;
            mergeSort(la, ra);

            int lb = m + 1, rb = r;
            mergeSort(lb, rb);

            vector<int> result;
            while (la <= ra && lb <= rb) {
                if (nums[la] < nums[lb]) {
                    result.push_back(nums[la++]);
                } else {
                    result.push_back(nums[lb++]);
                }
            }
            while (la <= ra) result.push_back(nums[la++]);
            while (lb <= rb) result.push_back(nums[lb++]);

            for (int i = 0; i < result.size(); ++i) nums[l + i] = result[i];
        };

        mergeSort(0, nums.size() - 1);

        return nums;
    }
};

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int n = r - l + 1;

        vector<int> buckets(n, 0);
        for (int v : nums) ++buckets[v - l];

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            int v = l + i;
            for (int j = 0; j < buckets[i]; ++j) {
                result.push_back(v);
            }
        }

        return result;
    }
};
