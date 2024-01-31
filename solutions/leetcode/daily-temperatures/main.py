class Solution:

    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0 for _ in range(n)]
        desc = []
        for r, t in enumerate(temperatures):
            while len(desc) > 0 and temperatures[desc[-1]] < t:
                l = desc.pop()
                result[l] = r - l
            desc.append(r)
        return result
