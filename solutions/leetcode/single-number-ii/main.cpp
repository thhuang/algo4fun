class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (int v : nums) {
            once = once ^ v & ~twice;
            twice = twice ^ v & ~once;
        }
        return once;
    }
};
