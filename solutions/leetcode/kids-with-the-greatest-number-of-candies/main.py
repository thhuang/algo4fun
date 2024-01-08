class Solution:

    def kidsWithCandies(self, candies: List[int],
                        extraCandies: int) -> List[bool]:
        max_candy = max(candies)
        return [v + extraCandies >= max_candy for v in candies]
