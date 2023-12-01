class Solution {
   public:
    vector<int> lexicalOrder(int n) {
        vector<int> result = {1};
        while (result.size() < n) {
            int v = result.back() * 10;
            while (v > n) {
                v = v / 10 + 1;
                while (v % 10 == 0) {
                    v = v / 10;
                }
            }
            result.push_back(v);
        }
        return result;
    }
};
