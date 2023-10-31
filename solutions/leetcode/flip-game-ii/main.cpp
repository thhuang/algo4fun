class Solution {
   public:
    bool canWin(string currentState) {
        int n = currentState.size();
        function<bool()> check = [&]() -> bool {
            for (int i = 0; i < n - 1; ++i) {
                if (currentState[i] != '+' || currentState[i + 1] != '+')
                    continue;
                currentState[i] = currentState[i + 1] = '-';
                bool win = !check();
                currentState[i] = currentState[i + 1] = '+';
                if (win) return true;
            }
            return false;
        };
        return check();
    }
};
