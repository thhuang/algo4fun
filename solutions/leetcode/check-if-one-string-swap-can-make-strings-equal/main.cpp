class Solution {
   public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> swap_targets;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) swap_targets.push_back(i);
            if (swap_targets.size() > 2) return false;
        }
        if (swap_targets.size() < 2) return swap_targets.size() == 0;
        if (s1[swap_targets[0]] == s2[swap_targets[1]] &&
            s1[swap_targets[1]] == s2[swap_targets[0]])
            return true;
        return false;
    }
};
