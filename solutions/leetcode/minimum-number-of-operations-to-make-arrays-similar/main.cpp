class Solution {
   public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> odd, even;
        for (int v : nums) {
            if (v % 2 == 0) {
                even.push_back(v);
            } else {
                odd.push_back(v);
            }
        }

        vector<int> todd, teven;
        for (int v : target) {
            if (v % 2 == 0) {
                teven.push_back(v);
            } else {
                todd.push_back(v);
            }
        }

        sort(odd.begin(), odd.end());
        sort(todd.begin(), todd.end());
        sort(even.begin(), even.end());
        sort(teven.begin(), teven.end());

        long long add = 0, sub = 0;
        for (int i = 0; i < odd.size(); ++i) {
            if (odd[i] < todd[i]) {
                add += (todd[i] - odd[i]) / 2;
            } else {
                sub += (odd[i] - todd[i]) / 2;
            }
        }
        for (int i = 0; i < even.size(); ++i) {
            if (even[i] < teven[i]) {
                add += (teven[i] - even[i]) / 2;
            } else {
                sub += (even[i] - teven[i]) / 2;
            }
        }

        return min(add, sub) + abs(add - sub);
    }
};
