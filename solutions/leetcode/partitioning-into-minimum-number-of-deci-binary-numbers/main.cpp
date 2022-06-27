class Solution {
   public:
    int minPartitions(string n) {
        int result = 0;
        for (char d : n) result = max(result, d - '0');
        return result;
    }
};
