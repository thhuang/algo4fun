class FoodRatings {
    unordered_map<string, map<int, set<string>>> cuisineRatingFood;
    unordered_map<string, pair<string, int>> foodCuisineRating;

   public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            foodCuisineRating[foods[i]] = {cuisines[i], ratings[i]};
            cuisineRatingFood[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodCuisineRating[food];

        foodCuisineRating[food] = {cuisine, newRating};
        auto it = cuisineRatingFood[cuisine][oldRating].find(food);
        cuisineRatingFood[cuisine][oldRating].erase(food);
        if (cuisineRatingFood[cuisine][oldRating].empty()) {
            cuisineRatingFood[cuisine].erase(oldRating);
        }
        cuisineRatingFood[cuisine][newRating].insert(food);
    }

    string highestRated(string cuisine) {
        return *cuisineRatingFood[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
