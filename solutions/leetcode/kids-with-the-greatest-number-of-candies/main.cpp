class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> result;
        for (int v : candies) result.push_back(v + extraCandies >= mx);
        return result;
    }
};
