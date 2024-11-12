class Solution:

    def maximumBeauty(self, items: List[List[int]],
                      queries: List[int]) -> List[int]:
        items.sort()

        price = [0]
        max_beauty = [0]
        mx = 0
        for p, b in items:
            mx = max(mx, b)
            price.append(p)
            max_beauty.append(mx)

        result = []
        for q in queries:
            i = bisect_right(price, q) - 1
            result.append(max_beauty[i])

        return result
