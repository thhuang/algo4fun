class Solution:

    def lengthOfLIS(self, nums: List[int]) -> int:
        seq = []
        for v in nums:
            i = bisect.bisect_left(seq, v)
            if i == len(seq):
                seq.append(v)
            else:
                seq[i] = v
        return len(seq)
