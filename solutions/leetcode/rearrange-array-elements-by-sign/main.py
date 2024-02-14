class Solution:

    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos, neg = [], []
        for v in nums:
            if v > 0:
                pos.append(v)
            else:
                neg.append(v)

        nums[0:len(nums):2] = pos
        nums[1:len(nums):2] = neg

        return nums
