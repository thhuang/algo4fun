class Solution:

    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        result = 0
        for i in range(len(flowerbed)):
            if flowerbed[i] == 1:
                continue
            if i - 1 >= 0 and flowerbed[i - 1] == 1:
                continue
            if i + 1 < len(flowerbed) and flowerbed[i + 1] == 1:
                continue
            flowerbed[i] = 1
            result += 1
        return result >= n
