class Solution:

    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        mp[0] = 1

        result = 0
        s = 0
        for v in nums:
            s = (s + v) % k
            result += mp[s]
            mp[s] += 1

        return result
