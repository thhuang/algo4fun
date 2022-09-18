class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> delta(n, 0);
        for (int i = 1; i < n; ++i) {
            delta[i] = delta[i - 1] + gas[i - 1] - cost[i - 1];
        }
        if (delta.back() + gas.back() - cost.back() < 0) return -1;
        return min_element(delta.begin(), delta.end()) - delta.begin();
    }
};

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int result = 0, mn = 0, curr = 0;
        for (int i = 1; i < n; ++i) {
            curr += gas[i - 1] - cost[i - 1];
            if (curr < mn) {
                mn = curr;
                result = i;
            }
        }
        if (curr + gas.back() - cost.back() < 0) return -1;
        return result;
    }
};
