class Solution(object):

    def cmp(self, a, b):
        if a + b > b + a:
            return -1
        elif a + b < b + a:
            return 1
        else:
            return 0

    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        strs = [str(v) for v in nums]
        strs.sort(cmp=self.cmp)
        result = "".join(strs)
        if result[0] == "0":
            return "0"
        return result
