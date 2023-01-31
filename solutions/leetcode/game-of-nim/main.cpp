class Solution {
   public:
    bool nimGame(vector<int>& piles) {
        int nim_sum = 0;
        for (int v : piles) nim_sum ^= v;
        return nim_sum != 0;
    }
};
