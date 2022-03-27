class Solution {
   public:
    int countCollisions(string directions) {
        int count = 0;
        for (int i = 0; i < directions.size(); ++i) {
            if (i > 0 && directions[i] == 'L' && directions[i - 1] != 'L') {
                ++count;
                directions[i] = 'S';
            }
        }
        for (int i = directions.size() - 1; ~i; --i) {
            if (i < directions.size() - 1 && directions[i] == 'R' &&
                directions[i + 1] != 'R') {
                ++count;
                directions[i] = 'S';
            }
        }
        return count;
    }
};
