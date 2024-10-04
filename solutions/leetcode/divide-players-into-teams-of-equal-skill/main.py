class Solution:

    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        t = skill[0] + skill[-1]

        result = 0
        for l in range(len(skill) // 2):
            r = len(skill) - l - 1
            if skill[l] + skill[r] != t:
                return -1
            result += skill[l] * skill[r]

        return result
