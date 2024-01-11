class Solution:

    def successfulPairs(self, spells: List[int], potions: List[int],
                        success: int) -> List[int]:
        potions.sort()

        result = []

        for s in spells:
            i = bisect.bisect_left(potions, success, key=lambda p: s * p)
            result.append(len(potions) - i)

        return result
