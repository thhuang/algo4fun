class Solution:

    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        order = deque([i for i in range(len(deck))])
        result = [None] * len(deck)
        for v in deck:
            result[order.popleft()] = v
            if len(order) > 0:
                order.append(order.popleft())
        return result
