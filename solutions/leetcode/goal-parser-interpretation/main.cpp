class Solution {
   public:
    string interpret(string command) {
        string ans;
        for (int i = 0; i < size(command); ++i) {
            if (command[i] == 'G') {
                ans += 'G';
                continue;
            }
            if (i + 1 < size(command) && command[i + 1] == 'a') {
                ans += "al";
                i += 3;
                continue;
            }
            ans += 'o';
            i += 1;
        }
        return ans;
    }
};
