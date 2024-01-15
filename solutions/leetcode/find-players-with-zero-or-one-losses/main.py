from collections import defaultdict


class Solution:

    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        players = set()
        lost_freq = defaultdict(int)
        for winner, loser in matches:
            players.add(winner)
            players.add(loser)
            lost_freq[loser] += 1

        result = [[], []]
        for p in sorted(players):
            if lost_freq[p] == 0:
                result[0].append(p)
            elif lost_freq[p] == 1:
                result[1].append(p)

        return result
