class Solution {
   public:
    int convertTime(string current, string correct) {
        int to = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int from = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int diff = to - from;

        array<int, 4> durations = {60, 15, 5, 1};
        int count = 0;
        for (int d : durations) {
            count += diff / d;
            diff %= d;
        }

        return count;
    }
};
