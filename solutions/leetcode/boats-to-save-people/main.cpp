class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        int result = 0;
        while (l <= r) {
            ++result;
            int w = people[r--];
            if (l <= r && w + people[l] <= limit) ++l;
        }
        return result;
    }
};
