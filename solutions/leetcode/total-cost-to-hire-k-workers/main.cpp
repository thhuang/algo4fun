class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        if (candidates * 2 > costs.size()) {
            sort(costs.begin(), costs.end());
            return accumulate(costs.begin(), costs.begin() + k, 0LL);
        }

        priority_queue<int, vector<int>, greater<>> left(costs.begin(), costs.begin() + candidates);
        priority_queue<int, vector<int>, greater<>> right(costs.end() - candidates, costs.end());
        
        long long result = 0;
        int l = candidates;
        int r = costs.size() - candidates - 1;
        while (k-- > 0) {
            if (left.top() <= right.top()) {
                result += left.top();
                left.pop();
                left.push(l <= r ? costs[l++] : numeric_limits<int>::max());
            } else {
                result += right.top();
                right.pop();
                right.push(l <= r ? costs[r--] : numeric_limits<int>::max());
            }
        }

        return result;
    }
};
