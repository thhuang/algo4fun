class Solution:

    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        total = 0
        r = 0
        for l, dt in customers:
            r = max(l, r) + dt
            total += r - l
        return total / len(customers)
