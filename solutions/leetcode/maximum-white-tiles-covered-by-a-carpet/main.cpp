class Solution {
   public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());

        int result = 0;
        for (int l = 0, r = 0, cover = 0; r < tiles.size(); ++r) {
            int white = tiles[r][1] - tiles[r][0] + 1;
            if (white >= carpetLen) return carpetLen;

            cover += white;

            while (l < r && tiles[l][1] + carpetLen <= tiles[r][1]) {
                cover -= tiles[l][1] - tiles[l][0] + 1;
                ++l;
            }

            int cut = max(0, tiles[r][1] - carpetLen - tiles[l][0] + 1);

            result = max(result, cover - cut);
        }

        return result;
    }
};
