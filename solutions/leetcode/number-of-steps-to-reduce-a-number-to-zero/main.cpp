class Solution {
   public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num) {
            ++count;
            if (num & 1) {
                --num;
            } else {
                num >>= 1;
            }
        }
        return count;
    }
};
