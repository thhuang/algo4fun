class Solution {
   public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int s1 = stoi(event1[0].substr(0, 2)) * 60 + stoi(event1[0].substr(3, 2));
        int e1 = stoi(event1[1].substr(0, 2)) * 60 + stoi(event1[1].substr(3, 2));
        int s2 = stoi(event2[0].substr(0, 2)) * 60 + stoi(event2[0].substr(3, 2));
        int e2 = stoi(event2[1].substr(0, 2)) * 60 + stoi(event2[1].substr(3, 2));
        if (e1 < s2) return false;
        if (e2 < s1) return false;
        return true;
    }
};
