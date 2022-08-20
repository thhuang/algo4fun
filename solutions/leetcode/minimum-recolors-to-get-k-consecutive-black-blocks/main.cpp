class Solution {
   public:
    int minimumRecolors(string blocks, int k) {
        int result = blocks.size();
        int count = 0;
        for (int i = 0; i < k - 1; ++i) {
            if (blocks[i] == 'W') ++count;
        }
        for (int i = k - 1; i < blocks.size(); ++i) {
            if (blocks[i] == 'W') ++count;
            result = min(result, count);
            if (blocks[i - k + 1] == 'W') --count;
        }
        return result;
    }
};
