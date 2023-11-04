class Solution {
   public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        if (!left.empty())
            result = max(result, *max_element(left.begin(), left.end()));
        if (!right.empty())
            result = max(result, n - *min_element(right.begin(), right.end()));
        return result;
    }
};
