class Solution {
   public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> flowers(n);
        iota(flowers.begin(), flowers.end(), 0);
        sort(flowers.begin(), flowers.end(), [&](int i, int j) -> bool {
            if (growTime[i] != growTime[j]) return growTime[i] > growTime[j];
            return plantTime[i] > plantTime[j];
        });

        int curr = 0, result = 0;
        for (int i : flowers) {
            curr += plantTime[i];
            result = max(result, curr + growTime[i]);
        }

        return result;
    }
};
