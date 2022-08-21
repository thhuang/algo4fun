class Solution {
   public:
    int minNumberOfHours(int initialEnergy, int initialExperience,
                         vector<int>& energy, vector<int>& experience) {
        int result = 0;

        result += max(
            0, accumulate(energy.begin(), energy.end(), 0) + 1 - initialEnergy);

        int exp = initialExperience;
        for (int v : experience) {
            if (exp <= v) {
                result += (v + 1 - exp);
                exp = v + 1;
            }
            exp += v;
        }

        return result;
    }
};
