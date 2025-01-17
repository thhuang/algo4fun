class Solution:

    def doesValidArrayExist(self, derived: List[int]) -> bool:
        return reduce(lambda acc, x: acc ^ x, derived) == 0
