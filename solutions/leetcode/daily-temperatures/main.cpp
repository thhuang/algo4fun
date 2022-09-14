class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);

        vector<int> desc;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!desc.empty() &&
                   temperatures[desc.back()] < temperatures[i]) {
                result[desc.back()] = i - desc.back();
                desc.pop_back();
            }
            desc.push_back(i);
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);

        for (int i = n - 1, mx = temperatures.back(); i >= 0; --i) {
            if (temperatures[i] >= mx) {
                mx = temperatures[i];
                continue;
            }
            int d = 1;
            while (temperatures[i] >= temperatures[i + d]) d += result[i + d];
            result[i] = d;
        }

        return result;
    }
};
