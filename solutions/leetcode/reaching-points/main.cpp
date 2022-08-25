class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx <= tx && sy <= ty) {
            if (sx == tx && sy == ty) return true;

            if (ty > tx) {
                swap(tx, ty);
                swap(sx, sy);
            }
            // tx >= ty

            if (ty > sx) {
                tx %= ty;
            } else {
                return sy == ty && (tx - sx) % ty == 0;
            }
        }
        return false;
    }
};
