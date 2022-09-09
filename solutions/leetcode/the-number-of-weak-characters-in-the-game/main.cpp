class Solution {
   public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int max_attack = 0;
        for (const vector<int>& p : properties) {
            max_attack = max(max_attack, p[0]);
        }

        vector<int> max_defence(max_attack + 2, 0);
        for (const vector<int>& p : properties) {
            max_defence[p[0]] = max(max_defence[p[0]], p[1]);
        }

        for (int i = max_attack; i >= 0; --i) {
            max_defence[i] = max(max_defence[i], max_defence[i + 1]);
        }

        int result = 0;
        for (const vector<int>& p : properties) {
            if (max_defence[p[0] + 1] > p[1]) ++result;
        }

        return result;
    }
};
