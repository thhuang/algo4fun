class Solution {
   public:
    double average(vector<int>& salary) {
        double sum = 0;
        int maximum = numeric_limits<int>::min();
        int minimum = numeric_limits<int>::max();
        for (int v : salary) {
            sum += v;
            maximum = max(maximum, v);
            minimum = min(minimum, v);
        }
        return (sum - maximum - minimum) / (size(salary) - 2);
    }
};
