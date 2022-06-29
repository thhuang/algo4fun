class Solution {
   public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        for (int i = 1; i < warehouse.size(); ++i) {
            warehouse[i] = min(warehouse[i], warehouse[i - 1]);
        }

        sort(boxes.begin(), boxes.end());

        int count = 0;
        for (int i = 0, j = warehouse.size() - 1; i < boxes.size(); ++i, --j) {
            while (j >= 0 && boxes[i] > warehouse[j]) --j;
            if (j < 0) break;
            ++count;
        }

        return count;
    }
};
