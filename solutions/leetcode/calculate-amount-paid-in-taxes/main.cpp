class Solution {
   public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double result = 0;
        for (int i = 0; i < brackets.size(); ++i) {
            int upper = brackets[i][0];
            int percent = brackets[i][1];
            int lower = 0;
            if (i > 0) lower = brackets[i - 1][0];

            if (upper >= income) {
                result += 0.01 * (income - lower) * percent;
                break;
            }
            result += 0.01 * (upper - lower) * percent;
        }
        return result;
    }
};
