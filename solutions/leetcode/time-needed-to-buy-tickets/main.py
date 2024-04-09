class Solution:

    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        result = 0
        for i in range(k + 1):
            result += min(tickets[i], tickets[k])
        for i in range(k + 1, len(tickets)):
            result += min(tickets[i], tickets[k] - 1)
        return result
