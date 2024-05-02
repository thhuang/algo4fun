class Solution:

    def findMaxK(self, nums: List[int]) -> int:
        mp = defaultdict(lambda: [False, False])
        for v in nums:
            mp[abs(v)][0 if v > 0 else 1] = True

        result = -1
        for v, [pos, neg] in mp.items():
            if pos and neg:
                result = max(result, v)

        return result
