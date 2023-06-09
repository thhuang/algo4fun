class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int v : asteroids) {
            while (!result.empty() && result.back() > 0 &&
                   result.back() + v < 0) {
                result.pop_back();
            }
            if (!result.empty() && result.back() > 0 && v < 0) {
                if (result.back() + v == 0) result.pop_back();
                continue;
            }
            result.push_back(v);
        }
        return result;
    }
};
