class Solution:

    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        result = [0] * len(temperatures)
        desc = []
        for r, t in enumerate(temperatures):
            while desc and temperatures[desc[-1]] < t:
                l = desc.pop()
                result[l] = r - l
            desc.append(r)
        return result
