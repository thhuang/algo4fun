class Solution {
    const double epsilon = 1e-6;

   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<int> cars(n);
        iota(cars.begin(), cars.end(), 0);
        sort(cars.begin(), cars.end(),
             [&](int i, int j) -> bool { return position[i] < position[j]; });

        vector<double> times;
        for (int i : cars) {
            times.push_back((double)(target - position[i]) / speed[i]);
        }

        int result = 0;
        double curr = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (times[i] - epsilon > curr) {
                curr = times[i];
                ++result;
            }
        }

        return result;
    }
};
