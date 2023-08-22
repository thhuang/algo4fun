class Solution {
   public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber) {
            result += 'A' + --columnNumber % 26;
            columnNumber = columnNumber / 26;
        }
        return {result.rbegin(), result.rend()};
    }
};
