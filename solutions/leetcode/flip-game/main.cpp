class Solution {
   public:
    vector<string> generatePossibleNextMoves(string currentState) {
        int n = currentState.size();

        vector<string> result;

        for (int i = 0; i < n - 1; ++i) {
            if (currentState[i] != '+' ||
                currentState[i] != currentState[i + 1])
                continue;
            currentState[i] = currentState[i + 1] = '-';
            result.push_back(currentState);
            currentState[i] = currentState[i + 1] = '+';
        }

        return result;
    }
};
