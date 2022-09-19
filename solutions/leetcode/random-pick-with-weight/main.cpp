class Solution {
    vector<int> acc;
    int offset;

    int rand() {
        int v = random();
        while (v < offset) v = random();
        return v % acc.back();
    }

   public:
    Solution(vector<int>& w) {
        for (int i = 0, s = 0; i < w.size(); ++i) acc.push_back(s += w[i]);
        offset = numeric_limits<int>::max() % acc.back();
    }

    int pickIndex() {
        return upper_bound(acc.begin(), acc.end(), rand()) - acc.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
