class Solution:

    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False

        freq = Counter(hand)

        for v in hand:
            if freq[v] == 0:
                continue

            l = v
            while l - 1 in freq:
                l -= 1

            for r in range(l, l + groupSize):
                if r not in freq:
                    return False
                freq[r] -= 1
                if freq[r] == 0:
                    del freq[r]

        return True
