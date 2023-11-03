class Solution {
   public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int i = 1;
        for (int v : target) {
            while (i < v) {
                result.push_back("Push");
                result.push_back("Pop");
                ++i;
            }
            result.push_back("Push");
            ++i;
        }
        return result;
    }
};
