class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        flowerbed.push_back(1);

        for (int l = 0; l < flowerbed.size(); ++l) {
            if (flowerbed[l] == 1) continue;

            int r = l + 1;

            while (flowerbed[r] != 1) ++r;

            n -= (r - l - 1) / 2;
            if (n <= 0) return true;

            l = r;
        }

        return false;
    }
};
