class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> result = {0};
        for (int k = 0; k < n; ++k) {
            for (int i = result.size() - 1; ~i; --i) {
                result[i] <<= 1;
                result.push_back(result[i] | 1);
            }
        }
        return result;
    }
};

class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> result = {};
        int k = 1 << n;
        for (int i = 0; i < k; ++i) {
            result.push_back(i ^ i >> 1);
        }
        return result;
    }
};
