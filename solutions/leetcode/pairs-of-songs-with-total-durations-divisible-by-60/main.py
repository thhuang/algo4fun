class Solution:

    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        prefix = defaultdict(int)

        result = 0

        for t in time:
            v = t % 60
            result += prefix[v]
            prefix[(60 - v) % 60] += 1

        return result
