class Solution:

    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        num_freq = defaultdict(int)
        result = []
        for v in nums:
            row = num_freq[v]
            if len(result) == row:
                result.append([])
            result[row].append(v)
            num_freq[v] += 1
        return result
