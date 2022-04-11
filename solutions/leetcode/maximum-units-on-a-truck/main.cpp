class Solution {
   public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });

        int sum = 0, capacity = truckSize;
        for (auto bt : boxTypes) {
            if (capacity > bt[0]) {
                sum += bt[0] * bt[1];
                capacity -= bt[0];
            } else {
                sum += capacity * bt[1];
                break;
            }
        }
        return sum;
    }
};
