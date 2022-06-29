class Solution {
   public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        for (int i = 1; i < warehouse.size(); ++i) {
            warehouse[i] = min(warehouse[i], warehouse[i - 1]);
        }

        sort(boxes.begin(), boxes.end());

        int cnt = 0;
        for (int i = warehouse.size() - 1; i >= 0; --i) {
            if (boxes[cnt] <= warehouse[i]) ++cnt;
            if (cnt == boxes.size()) break;
        }

        return cnt;
    }
};
