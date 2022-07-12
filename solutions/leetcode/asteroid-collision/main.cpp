class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int v : asteroids) {
            if (v > 0) {
                result.push_back(v);
                continue;
            }
            while (true) {
                if (result.empty() || result.back() < 0) {
                    result.push_back(v);
                    break;
                }
                if (result.back() + v == 0) {
                    result.pop_back();
                    break;
                }
                if (result.back() + v > 0) {
                    break;
                }
                result.pop_back();
            }
        }
        return result;
    }
};
