class Solution:

    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()

        result = 0
        l, r = 0, len(tokens) - 1
        score = 0

        while l <= r:
            if tokens[l] <= power:
                power -= tokens[l]
                l += 1
                score += 1
            elif score > 0:
                power += tokens[r]
                r -= 1
                score -= 1
            else:
                break
            result = max(result, score)

        return result
