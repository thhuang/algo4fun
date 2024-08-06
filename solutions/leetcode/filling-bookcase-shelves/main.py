class Solution:

    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        n = len(books)

        dp = [inf] * (n + 1)
        dp[-1] = 0

        for l in reversed(range(n)):
            r = l
            w = 0
            h = 0
            while r < n:
                if w + books[r][0] > shelf_width:
                    break
                w += books[r][0]
                h = max(h, books[r][1])
                dp[l] = min(dp[l], dp[r + 1] + h)
                r += 1

        return dp[0]
