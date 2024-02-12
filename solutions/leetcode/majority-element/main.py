class Solution:

    def majorityElement(self, nums: List[int]) -> int:
        result = inf
        cnt = 0
        for v in nums:
            if v != result:
                cnt -= 1
                if cnt < 0:
                    result, cnt = v, 1
            else:
                cnt += 1
        return result
