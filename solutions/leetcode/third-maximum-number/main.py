class Solution:

    def thirdMax(self, nums: List[int]) -> int:
        max_three = []
        for v in nums:
            if v in max_three:
                continue
            max_three.append(v)
            max_three.sort(reverse=True)
            if len(max_three) > 3:
                max_three.pop()
        return max_three[2 % len(max_three)]
