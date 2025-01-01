class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)
        num_total_zeros = s.count("0")

        result = 0
        left_zeros = 0
        right_ones = n - num_total_zeros
        for c in s[: n - 1]:
            if c == "0":
                left_zeros += 1
            else:  # c == "1"
                right_ones -= 1
            result = max(result, left_zeros + right_ones)

        return result


class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)
        result = 0
        state = n - s.count("0")
        for c in s[: n - 1]:
            if c == "0":
                state += 1
            else:  # c == "1"
                state -= 1
            result = max(result, state)

        return result
