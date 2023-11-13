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

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int result = 0, g = 0;
        for (int i = 0, mn = 0; i < n; ++i) {
            g += gas[i] - cost[i];
            if (g < mn) {
                mn = g;
                result = (i + 1) % n;
            }
        }
        return (g < 0) ? -1 : result;
    }
};

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int result = 0;
        for (int i = 0, curr = -cost.back(), mn = -cost.back(); i < gas.size();
             ++i) {
            if (curr < mn) {
                mn = curr;
                result = i;
            }
            curr += gas[i] - cost[i];
        }
        return result;
    }
};
