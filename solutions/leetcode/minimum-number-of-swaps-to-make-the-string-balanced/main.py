class Solution:

    def minSwaps(self, s: str) -> int:
        arr = [c for c in s]

        open_idx = []
        for i, c in enumerate(arr):
            if c == "[":
                open_idx.append(i)

        result = 0

        opens = 0
        for i, c in enumerate(arr):
            if c == "[":
                opens += 1
            elif c == "]":
                opens -= 1
                if opens < 0:
                    arr[i], arr[open_idx[-1]] = arr[open_idx[-1]], arr[i]
                    open_idx.pop()
                    opens += 2
                    result += 1

        return result


class Solution:

    def minSwaps(self, s: str) -> int:
        unmatched = 0

        for c in s:
            if c == "[":
                unmatched += 1
            elif unmatched > 0:
                unmatched -= 1

        return (unmatched + 1) // 2
