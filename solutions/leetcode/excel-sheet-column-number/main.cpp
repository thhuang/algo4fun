class Solution {
   public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        uint b = 1;
        for (auto it = columnTitle.rbegin(); it != columnTitle.rend(); ++it) {
            result += b * (*it - 'A' + 1);
            b *= 26;
        }
        return result;
    }
};
