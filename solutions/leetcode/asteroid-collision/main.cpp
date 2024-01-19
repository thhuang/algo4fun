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

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int v : asteroids) {
            if (v > 0) {
                result.push_back(v);
                continue;
            }
            while (!result.empty() && 0 < result.back() && result.back() < -v) {
                result.pop_back();
            }
            if (result.empty() || result.back() < 0) {
                result.push_back(v);
            } else if (result.back() == -v) {
                result.pop_back();
            }
        }
        return result;
    }
};
