class Solution {
   public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        for (int v : position) {
            if (v & 1) ++odd;
        }
        return min(odd, (int)position.size() - odd);
    }
};
