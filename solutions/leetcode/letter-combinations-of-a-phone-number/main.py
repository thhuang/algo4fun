class Solution:

    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []

        mp = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        result = []
        curr = []

        def dfs(i):
            if i == len(digits):
                result.append("".join(curr))
                return
            for c in mp[digits[i]]:
                curr.append(c)
                dfs(i + 1)
                curr.pop()

        dfs(0)

        return result
