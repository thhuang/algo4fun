class Solution:

    def numberOfBeams(self, bank: List[str]) -> int:
        result = 0

        prev = 0
        for row in bank:
            curr = 0
            for c in row:
                if c == '1':
                    curr += 1
            if curr != 0:
                result += prev * curr
                prev = curr

        return result
