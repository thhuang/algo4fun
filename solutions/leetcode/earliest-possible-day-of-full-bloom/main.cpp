class Solution {
   public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> flowers(n);
        iota(flowers.begin(), flowers.end(), 0);

        sort(flowers.begin(), flowers.end(),
             [&](int a, int b) -> bool { return growTime[a] > growTime[b]; });

        int result = 0;
        int t = 0;
        for (int i : flowers) {
            t += plantTime[i];
            result = max(result, t + growTime[i]);
        }

        return result;
    }
};
