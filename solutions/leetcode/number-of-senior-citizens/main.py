class Solution:

    def countSeniors(self, details: List[str]) -> int:
        result = 0
        for s in details:
            if int(s[11:13]) > 60:
                result += 1
        return result
