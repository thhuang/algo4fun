class Solution {
   public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        for (int i = 0, h = warehouse.front(); i < n; ++i) {
            h = min(h, warehouse[i]);
            warehouse[i] = h;
        }

        sort(boxes.begin(), boxes.end());

        int count = 0;
        for (int i = n - 1, j = 0; i >= 0 && j < boxes.size(); --i, ++j) {
            while (i >= 0 && boxes[j] > warehouse[i]) --i;
            if (i < 0) break;
            ++count;
        }

        return count;
    }
};
