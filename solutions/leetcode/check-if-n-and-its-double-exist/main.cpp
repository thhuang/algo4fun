class Solution {
   public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> target;
        for (int v : arr) {
            if (target.count(v)) return true;
            target.insert(v * 2);
            if (v % 2 == 0) target.insert(v / 2);
        }
        return false;
    }
};
