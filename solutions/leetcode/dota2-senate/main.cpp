class Solution {
   public:
    string predictPartyVictory(string senate) {
        int dCount = 0, dBan = 0;
        int rCount = 0, rBan = 0;

        queue<char> q;
        for (char c : senate) {
            q.push(c);
            if (c == 'R') {
                ++rCount;
            } else {
                ++dCount;
            }
        }

        while (rCount > 0 && dCount > 0) {
            char c = q.front();
            q.pop();

            if (c == 'R') {
                if (rBan > 0) {
                    --rBan;
                    --rCount;
                } else {
                    ++dBan;
                    q.push('R');
                }
            } else {
                if (dBan > 0) {
                    --dBan;
                    --dCount;
                } else {
                    ++rBan;
                    q.push('D');
                }
            }
        }

        return rCount > 0 ? "Radiant" : "Dire";
    }
};
