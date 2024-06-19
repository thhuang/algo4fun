class Solution:

    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(profit, difficulty))

        result = 0

        for w in sorted(worker, reverse=True):
            while len(jobs) > 0 and jobs[-1][1] > w:
                jobs.pop()
            if len(jobs) == 0:
                break
            result += jobs[-1][0]

        return result
