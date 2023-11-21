class Solution {
   public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        auto collect = [&](char target) -> int {
            int r = -1;
            int garbageCount = 0;
            int travelTime = 0;
            for (int i = 0, t = 0; i < garbage.size(); ++i) {
                int cnt = 0;
                for (char g : garbage[i]) {
                    if (g == target) ++cnt;
                }
                if (cnt > 0) {
                    garbageCount += cnt;
                    travelTime += t;
                    t = 0;
                }
                if (i < travel.size()) {
                    t += travel[i];
                }
            }
            return garbageCount + travelTime;
        };

        return collect('M') + collect('P') + collect('G');
    }
};
