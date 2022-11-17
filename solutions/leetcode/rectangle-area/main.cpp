class Solution {
   public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        int cx1 = max(ax1, bx1);
        int cy1 = max(ay1, by1);
        int cx2 = min(ax2, bx2);
        int cy2 = min(ay2, by2);

        int sub = 0;
        if (cx1 < cx2 && cy1 < cy2) sub = (cx2 - cx1) * (cy2 - cy1);

        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - sub;
    }
};
