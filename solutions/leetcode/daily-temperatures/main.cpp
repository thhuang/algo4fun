class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);

        vector<array<int, 2>> tempDays;  // {temp, day}
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!tempDays.empty() && tempDays.back()[0] < temperatures[i]) {
                auto [_, d] = tempDays.back();
                tempDays.pop_back();
                result[d] = i - d;
            }
            tempDays.push_back({temperatures[i], i});
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);

        vector<int> days;  // {temp, day}
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!days.empty() &&
                   temperatures[days.back()] < temperatures[i]) {
                int d = days.back();
                days.pop_back();
                result[d] = i - d;
            }
            days.push_back(i);
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
            while (temperatures[i] >= temperatures[i + d]) {
                d += result[i + d];
            }
            result[i] = d;
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> result(n, 0);
        vector<int> decTempIdx;

        for (int i = 0; i < n; ++i) {
            while (!decTempIdx.empty() &&
                   temperatures[decTempIdx.back()] < temperatures[i]) {
                int j = decTempIdx.back();
                decTempIdx.pop_back();
                result[j] = i - j;
            }
            decTempIdx.push_back(i);
        }

        return result;
    }
};
